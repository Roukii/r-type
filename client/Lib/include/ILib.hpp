//
// Created by Samy on 18/01/2018.
//

#ifndef R_TYPE_ILIB_HPP
#define R_TYPE_ILIB_HPP

#include <memory>
#include <iostream>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Music.hpp>

#include "EntityGraphique.hpp"
#include "Entity.hpp"

class ILib {
public:
	ILib() = default;
	virtual ~ILib() = default;
	virtual void 		init() = 0;
	virtual void		loadLib() = 0;
	virtual void		loadSprite(const std::string &path, const std::string &name) = 0;
	virtual void		deleteSprite(const std::string&) = 0;
	virtual void		loadFont(const std::string &path) = 0;
	virtual void		loadText(float x, float y, unsigned int size, const std::string &str, const std::string &name) = 0;
	virtual void		loadSound(const std::string &path, const std::string &name) = 0;
	virtual void		loadMusic(const std::string &path, const std::string &name) = 0;
	virtual int         handleMenu() = 0;
	virtual int         handleSplash() = 0;
	virtual int         handleGame(std::map<int, UgandaEngine::Entity *> &) = 0;
	virtual int         handleConnexion() = 0;
	virtual int         handleLobby() = 0;
	virtual int         handleReady() = 0;
	virtual int         handleOption() = 0;
	virtual int         handleChangeOption() = 0;
	virtual std::string getIpAdress() = 0;
	virtual std::string getPort() = 0;
	virtual int getJoin() = 0;
	virtual void setPlayer(std::string room, std::string players) = 0;
	virtual std::vector<char> handleClientAction() = 0;
	virtual std::shared_ptr<EntityFactoryData>	    factoryData(const std::string&) = 0;
	virtual std::shared_ptr<sf::Sprite>	getSprite(const std::string& name) = 0;
	virtual std::shared_ptr<sf::Music>	getMusic(const std::string& name) = 0;
	virtual std::shared_ptr<Animation>	getAnimation(const std::string& name) = 0;
	virtual std::shared_ptr<sf::RenderWindow> getWindow() = 0;
};

#endif //R_TYPE_ILIB_HPP
