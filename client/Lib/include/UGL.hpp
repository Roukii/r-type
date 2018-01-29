//
// Created by alex on 1/18/18.
//

#ifndef DISPLAYTESTS_UGL_HPP
#define DISPLAYTESTS_UGL_HPP

// UGL means Uganda Graphic Library

#include <map>
#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "Animation.hpp"
#include "ILib.hpp"
#include "EntityGraphique.hpp"
#include "Random.h"


enum eEntityType {
	NONE = 0,
	SHIP,
    ENNEMY,
	SHOOT,
	BACKGROUND
};

struct Star {
	Star() : _shape(2), _beginPos({0, 0}), _actualPos({0, 0}) {
		Random<int> rdm;
		_beginPos.x = rdm.Generate(0, 1920);
		_shape.setFillColor(sf::Color::White);
		_reset = false;
	}

	sf::CircleShape	_shape;
	sf::Vector2f 	_beginPos;
	sf::Vector2f 	_actualPos;
	bool 		_reset;
};

class UGL : public ILib {
public:
	UGL();
	~UGL() override;
	std::shared_ptr<sf::RenderWindow> getWindow() {return _window;}
protected:
	int selected = 0;
	float alpha = 255;
	int aState = 0;
	int boxSelected = 1;
	int joinSelected = 0;
	std::string players[4];
	std::string item[2];
	sf::RectangleShape ip;
	sf::RectangleShape port;
	sf::RectangleShape join[4];
	std::string	_keybinding[5];

	void 		init() override;
	void		loadLib() override;
	void		loadSprite(const std::string &path, const std::string &name) override;
	std::shared_ptr<sf::Texture>	textureFactory(const std::string&);

public:
	std::shared_ptr<sf::Sprite>	getSprite(const std::string& name) override { return _sprites[name].first; }
	std::shared_ptr<sf::Sound>	getSound(const std::string& name) {return _sounds[name].first;};
	std::shared_ptr<sf::Music>	getMusic(const std::string& name) {return _musics[name];};
	std::shared_ptr<sf::Text>	getText(const std::string& name) {return _texts[name];};
	std::shared_ptr<sf::Texture>	getTexture(const std::string& name) { return _sprites[name].second; }
	eEntityType	getEntity(const std::string&);
	std::shared_ptr<Animation>	getAnimation(const std::string& name) override { return _animations[name]; }

protected:
	void		deleteSprite(const std::string& name) override;
	void		loadFont(const std::string &path) override;
	void		loadText(float x, float y, unsigned int size, const std::string &str, const std::string &name) override;
	void		loadSound(const std::string &path, const std::string &name) override;
	void		loadMusic(const std::string &path, const std::string &name) override;
	void 		loadAnimation(const std::shared_ptr<sf::Texture>&, const std::string&);

	std::vector<std::shared_ptr<Animation>>	animationFactory(const std::string&);
	std::shared_ptr<EntityFactoryData>	    factoryData(const std::string&) override;

	void moveUp();
	int handleMenu() override;
	void moveDown();
	int handleKeys(const sf::Event &e);

	int handleSplash() override;
	void handleAlpha();

	int handleConnexion() override;
	void handleKeysConnexion(const sf::Event &e);

	int handleLobby() override;
	void setPlayer(std::string room, std::string players);

	std::string getIpAdress() {return item[0];};
	std::string getPort(){return item[1];};

	void 	starfield();

	int         handleGame(std::map<int, UgandaEngine::Entity *> &) override;
	int getJoin() {return joinSelected;};

	int		handleOption() override;
	int 	handleChangeOption() override;

	int		handleReady() override;

	std::shared_ptr<sf::RenderWindow>	_window;
	sf::Font			_font;
	std::map<std::string, std::pair<std::shared_ptr<sf::Sprite>, std::shared_ptr<sf::Texture>>>	_sprites;
	std::map<std::string, std::pair<std::shared_ptr<sf::Sound>, std::shared_ptr<sf::SoundBuffer>>> 	_sounds;
	std::map<std::string, std::shared_ptr<sf::Music>>	_musics;
	std::map<std::string, std::shared_ptr<sf::Text>>	_texts;
	std::map<std::string, std::shared_ptr<Animation>>	_animations;

	std::vector<char> handleClientAction() override;
};

#endif /* DISPLAYTESTS_UGL_HPP */
