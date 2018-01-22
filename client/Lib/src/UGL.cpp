//
// Created by alex on 1/18/18.
//


#include "../include/UGL.hpp"
#include "../../../utils/GameEngine/include/Entity.hpp"

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
			getSprite("Ship1");
			break;
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
	_texts[name]->setPosition(x, y);
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
		ret.push_back(_animations[item2]);
	}

	return ret;
}

std::shared_ptr<EntityFactoryData>	UGL::factoryData(const std::string& entityName) {
	return std::make_shared<EntityFactoryData>(textureFactory(entityName), animationFactory(entityName));
}

extern "C" {
	ILib		*create_lib() {
    		return new UGL();
	}
}
