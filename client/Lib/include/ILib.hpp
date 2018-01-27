//
// Created by Samy on 18/01/2018.
//

#ifndef R_TYPE_ILIB_HPP
#define R_TYPE_ILIB_HPP

#include <memory>
#include <iostream>
#include <vector>
#include "EntityGraphique.hpp"

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
	virtual int         handleConnexion() = 0;
	virtual int         handleLobby() = 0;
	virtual std::string getIpAdress() = 0;
	virtual std::string getPort() = 0;
	virtual std::vector<char> handleClientAction() = 0;
	virtual std::shared_ptr<EntityFactoryData>	    factoryData(const std::string&) = 0;
};

#endif //R_TYPE_ILIB_HPP
