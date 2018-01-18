//
// Created by alex on 1/18/18.
//

#ifndef DISPLAYTESTS_UGL_HPP
#define DISPLAYTESTS_UGL_HPP

// UGL means Uganda Graphic Library

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <functional>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Music.hpp>
#include "ILib.hpp"

class UGL : public ILib {
public:
	UGL() = default;
	~UGL() = default;
protected:
    void loadLib();
    void loadSprite(const std::string &path, const std::string &name);
    void loadFont(const std::string &path);
    void loadText(float x, float y, unsigned int size, const std::string &str, const std::string &name);
    void loadSound(const std::string &path, const std::string &name);
    void loadMusic(const std::string &path, const std::string &name);

	sf::RenderWindow	_window;
    sf::Font _font;
    std::map<std::string, std::pair<std::shared_ptr<sf::Sprite>, std::shared_ptr<sf::Texture>>> _sprites;
    std::map<std::string, std::pair<std::shared_ptr<sf::Sound>, std::shared_ptr<sf::SoundBuffer>>> _sound;
    std::map<std::string, std::shared_ptr<sf::Music>> _music;
    std::map<std::string, std::shared_ptr<sf::Text>> _texts;
};


#endif /* DISPLAYTESTS_UGL_HPP */
