//
// Created by Samy on 18/01/2018.
//

#ifndef R_TYPE_ILIB_HPP
#define R_TYPE_ILIB_HPP

#include <memory>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Window/Event.hpp>

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
	virtual sf::Sprite	*getSprite(const std::string& name) = 0;
	virtual sf::Sound	*getSound(const std::string& name) = 0;
	virtual sf::Text	*getText(const std::string& name) = 0;
	virtual std::shared_ptr<EntityFactoryData>	    factoryData(const std::string&) = 0;
	virtual std::shared_ptr<sf::RenderWindow> getWindow() = 0;
};

#endif //R_TYPE_ILIB_HPP
