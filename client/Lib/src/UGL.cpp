//
// Created by alex on 1/18/18.
//

#include "UGL.hpp"
#include "Entity.hpp"

UGL::UGL() : _window(std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "R-Type"))
{
    // Tous les emplacement sprite avec un nom => remplir toutes ses map
}

UGL::~UGL()
{
	_window->close();
}

void 		UGL::init() {
	/*_texture = new sf::Texture;
	if (!_texture->loadFromFile("assets/ship_1.png"))
		throw std::invalid_argument("Error: Cannot load image");*/

	loadSprite("../assets/ship_1.png", "Ship1");
	// UP ANIM
	loadAnimation(_sprites["Ship1"].second, "Ship1_animation_up");
	_animations["Ship1_animation_up"]->addFrame(sf::IntRect(85, 14, 23, 10));
	_animations["Ship1_animation_up"]->addFrame(sf::IntRect(60, 14, 22, 10));
	_animations["Ship1_animation_up"]->addFrame(sf::IntRect(34, 12, 23, 13));
	_animations["Ship1_animation_up"]->addFrame(sf::IntRect(8, 11, 23, 15));

	// DOWN ANIM
	loadAnimation(_sprites["Ship1"].second, "Ship1_animation_down");
	_animations["Ship1_animation_down"]->addFrame(sf::IntRect(137, 14, 23, 10));
	_animations["Ship1_animation_down"]->addFrame(sf::IntRect(163, 15, 23, 10));
	_animations["Ship1_animation_down"]->addFrame(sf::IntRect(189, 12, 22, 13));
	_animations["Ship1_animation_down"]->addFrame(sf::IntRect(214, 11, 23, 15));

	loadAnimation(_sprites["Ship1"].second, "Ship1_animation_none");
	_animations["Ship1_animation_none"]->addFrame(sf::IntRect(111, 13, 23, 11));

	loadSprite("../assets/Stars.jpg", "Background1");
	getSprite("Background1")->setColor(sf::Color::Cyan);

	loadSprite("../assets/HandCursor.gif", "Cursor1");
	getSprite("Cursor1")->setPosition(90 * 20 / 6, 580);

	loadSound("../assets/cursor.ogg", "Cursor2");

	loadFont("../assets/Enter-The-Grid.ttf");

	loadText(90 * 20 / 5, 550, 60, "New Game", "New Game");
	loadText(90 * 20 / 5, 650, 60, "Options", "Options");
	loadText(90 * 20 / 5, 750, 60, "Quit", "Quit");
	loadText(90 * 20 / 2.8, 150, 200, "R TYPE", "R TYPE");
	loadText(250, 850, 100, "PRESS A KEY TO CONTINUE", "PRESS KEY");
	loadText(250, 850, 100, "PRESS SPACE TO CONTINUE", "PRESS SPACE");
	loadText(400, 200, 60, "IP ADRESS", "IP ADRESS");
	loadText(400, 400, 60, "PORT", "PORT");
	loadText(410, 285, 60, item[0], "ITEM 0");
	loadText(410, 485, 60, item[1], "ITEM 1");
	(*getText("ITEM 0")).setColor(sf::Color::Black);
	(*getText("ITEM 1")).setColor(sf::Color::Black);

	ip.setSize(sf::Vector2f(500, 80));
	ip.setPosition(sf::Vector2f(400, 280));

	port.setSize(sf::Vector2f(500, 80));
	port.setPosition(sf::Vector2f(400, 480));
}

void		UGL::loadSprite(const std::string &path, const std::string &name) {
	_sprites.emplace(name, std::make_pair(std::make_shared<sf::Sprite>(), std::make_shared<sf::Texture>()));
	if (!_sprites[name].second->loadFromFile(path))
		throw std::invalid_argument("Error: Unable to load Texture " + path);
	_sprites[name].first->setTexture(*_sprites[name].second);
}

eEntityType	UGL::getEntity(const std::string& entityType) {
	if (entityType == "Ship")
		return SHIP;
	return NONE;
}

std::shared_ptr<sf::Texture>	UGL::textureFactory(const std::string& entityName) {
	switch (getEntity(entityName)) {
		case SHIP:
			return getTexture("Ship1");
		default:
			break;
	};
}

void		UGL::loadFont(const std::string &path) {
	if (!_font.loadFromFile(path))
		throw std::invalid_argument("error loading font");
}

void		UGL::loadLib() {}

void		UGL::deleteSprite(const std::string& name) {
	_sprites.erase(name);
}

void		UGL::loadText(float x, float y, unsigned int size, const std::string &str, const std::string &name) {
	_texts[name] = std::make_shared<sf::Text>(str, _font);
	_texts[name]->setPosition(sf::Vector2f(x, y));
	_texts[name]->setCharacterSize(size);
}

void		UGL::loadSound(const std::string &path, const std::string &name) {
	_sounds.emplace(name, std::make_pair(std::make_shared<sf::Sound>(), std::make_shared<sf::SoundBuffer>()));
	if (!_sounds[name].second->loadFromFile(path))
		throw std::invalid_argument("Error: Unable to load SoundBuffer " + path);
	_sounds[name].first->setBuffer(*_sounds[name].second);
}

void		UGL::loadMusic(const std::string &path, const std::string &name) {
	_musics[name] = std::make_shared<sf::Music>();
	if (!_musics[name]->openFromFile(path))
		throw std::invalid_argument("Error: Unable to load Music " + path);
}

void 		UGL::loadAnimation(const std::shared_ptr<sf::Texture>& texture, const std::string& name) {
	_animations[name] = std::make_shared<Animation>();
	_animations[name]->setSpriteSheet(*texture);
}

std::vector<std::shared_ptr<Animation>>	UGL::animationFactory(const std::string& entityName) {
	std::vector<std::string>	keys;
	for (auto& item : _animations) {
		keys.push_back(item.first);
	}

	std::vector<std::string>	corresp;
	for (auto& key : keys) {
		if (key.find(entityName))
			corresp.push_back(key);
	}

	std::vector<std::shared_ptr<Animation>>	ret;

	for (auto& item2 : corresp) {
		ret.push_back(std::move(_animations[item2]));
	}

	return ret;
}

std::shared_ptr<EntityFactoryData>	UGL::factoryData(const std::string& entityName) {
	return std::make_shared<EntityFactoryData>(textureFactory(entityName), animationFactory(entityName));
}


void    UGL::moveUp() {
	if (selected == 0) {
		getSprite("Background1").get()->setColor(sf::Color::Red);
		getSprite("Cursor1").get()->setPosition(90 * 20 / 6, 780);
		selected = 2;
	} else if (selected == 1) {
		getSprite("Background1").get()->setColor(sf::Color::Magenta);
		getSprite("Cursor1").get()->setPosition(90 * 20 / 6, 580);
		selected = 0;
	} else {
		getSprite("Background1").get()->setColor(sf::Color::Green);
		getSprite("Cursor1").get()->setPosition(90 * 20 / 6, 680);
		selected = 1;
	}
	getSound("Cursor2").get()->play();
}

void    UGL::moveDown()
{
	if (selected == 0) {
		getSprite("Background1").get()->setColor(sf::Color::Green);
		getSprite("Cursor1").get()->setPosition(90 * 20 / 6, 680);
		selected = 1;
	} else if (selected == 1) {
		getSprite("Background1").get()->setColor(sf::Color::Red);
		getSprite("Cursor1").get()->setPosition(90 * 20 / 6, 780);
		selected = 2;
	} else {
		getSprite("Background1").get()->setColor(sf::Color::Magenta);
		getSprite("Cursor1").get()->setPosition(90 * 20 / 6, 580);
		selected = 0;
	}
	getSound("Cursor2").get()->play();
}

int UGL::handleKeys(const sf::Event&e) {
	int ret = 1;
	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Up) {
			moveUp();
		} else if (e.key.code == sf::Keyboard::Down) {
			moveDown();
		} else if (e.key.code == sf::Keyboard::Space) {
			if (selected == 0)
				ret = 3;
			else if (selected == 1)
				ret = 2;
			else
				ret = -2;
		}
	}
	return ret;
}

int UGL::handleMenu() {
	sf::Event event;
	int ret;
	while (getWindow()->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			getWindow()->close();
		if ((ret = handleKeys(event)) != 1)
			return ret;
	}
	if (getWindow() != nullptr) {
		getWindow()->clear();

		getWindow()->draw(*getSprite("Background1").get());
		getWindow()->draw(*getSprite("Cursor1").get());
		getWindow()->draw(*getText("New Game").get());
		getWindow()->draw(*getText("Options").get());
		getWindow()->draw(*getText("Quit").get());
		getWindow()->draw(*getText("R TYPE").get());
		getWindow()->display();
		return -1;
	} else
		throw std::invalid_argument("Error: MenuState.cpp: Windows is null");
}

void UGL::handleAlpha() {
	if (alpha >= 255)
		aState = 1;
	else if (alpha <= 0)
		aState = 0;
	if (aState == 0)
		alpha += 0.2;
	else
		alpha -= 0.2;
	getText("PRESS KEY")->setColor(sf::Color(255,255,255,alpha));
	getText("PRESS SPACE")->setColor(sf::Color(255,255,255,alpha));
}

int UGL::handleSplash() {
	sf::Event event;
	int ret;
	while (getWindow()->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			getWindow()->close();
		if (event.type == sf::Event::KeyPressed) {
			return 4;
		}
	}
	if (getWindow() != nullptr) {
		handleAlpha();
		getWindow()->clear();
		//TODO SPLASHSCREEN
		getWindow()->draw(*getSprite("Background1").get());
		getWindow()->draw(*getText("PRESS KEY").get());
		getWindow()->display();
		return -1;
	} else
		throw std::invalid_argument("Error: MenuState.cpp: Windows is null");
}

int UGL::handleLobby() {
	sf::Event event;
	while (getWindow()->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			getWindow()->close();
		if (event.type == sf::Event::KeyPressed) {
			getSprite("Background1").get()->setColor(sf::Color::Magenta);
			return 1;
		}
	}
	if (getWindow() != nullptr) {
		handleAlpha();
		getWindow()->clear();
		//TODO LOBBY
		getWindow()->draw(*getSprite("Background1").get());
		getWindow()->draw(*getText("PRESS KEY").get());
		getWindow()->display();
		return -1;
	} else
		throw std::invalid_argument("Error: MenuState.cpp: Windows is null");
}

void UGL::handleKeysConnexion(const sf::Event&e) {
	if (e.type == sf::Event::MouseButtonPressed) {
		if (e.mouseButton.button == sf::Mouse::Left) {
			if (e.mouseButton.x > 400 && e.mouseButton.x < 900
				&& e.mouseButton.y > 280 && e.mouseButton.y < 360) {
				boxSelected = 1;
				ip.setFillColor(sf::Color::Green);
				port.setFillColor(sf::Color::White);
			} else if (e.mouseButton.x > 400 && e.mouseButton.x < 900
					   && e.mouseButton.y > 480 && e.mouseButton.y < 560) {
				boxSelected = 2;
				port.setFillColor(sf::Color::Green);
				ip.setFillColor(sf::Color::White);
			} else {
				boxSelected = 0;
				ip.setFillColor(sf::Color::White);
				port.setFillColor(sf::Color::White);
			}
		}
	} else if (e.type == sf::Event::TextEntered && boxSelected != 0) {
		if (e.text.unicode == '\b') {
			if (item[boxSelected - 1].size() > 0)
				item[boxSelected - 1].erase(item[boxSelected - 1].size() - 1, 1);
			if (boxSelected == 1)
				(*getText("ITEM 0").get()).setString(item[0]);
			else if (boxSelected == 1)
				(*getText("ITEM 1").get()).setString(item[1]);
		} else if ((e.text.unicode >= '0' && e.text.unicode <= '9') ||
				   e.text.unicode == '.') {
			if (boxSelected == 2 && (e.text.unicode >= '0' && e.text.unicode <= '9')) {
				item[1] += static_cast<char>(e.text.unicode);
				(*getText("ITEM 1").get()).setString(item[1]);
			} else if (boxSelected == 1 && ((e.text.unicode >= '0' &&
										  e.text.unicode <= '9') || e.text.unicode == '.')) {
				item[0] += static_cast<char>(e.text.unicode);
				(*getText("ITEM 0").get()).setString(item[0]);
			}
		}
	}
}

int UGL::handleConnexion() {
	sf::Event event;
	while (getWindow()->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			getWindow()->close();
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) {
			//TODO	if connexion reussi
				return 5;
			}
		}
		handleKeysConnexion(event);
	}
	if (getWindow() != nullptr) {
		handleAlpha();
		getWindow()->clear();
		getWindow()->draw(*getSprite("Background1").get());
		getWindow()->draw(*getText("IP ADRESS").get());
		getWindow()->draw(*getText("PORT").get());
		getWindow()->draw(ip);
		getWindow()->draw(port);
		getWindow()->draw(*getText("ITEM 0").get());
		getWindow()->draw(*getText("ITEM 1").get());
		getWindow()->draw(*getText("PRESS SPACE").get());
		getWindow()->display();
		return -1;
	} else
		throw std::invalid_argument("Error: MenuState.cpp: Windows is null");
}

extern "C" {
	ILib		*create_lib() {
    		return new UGL();
	}
}
