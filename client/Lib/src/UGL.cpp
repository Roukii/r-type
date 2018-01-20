//
// Created by alex on 1/18/18.
//

#include "../include/UGL.hpp"

UGL::UGL() : _window(sf::VideoMode(1920, 1080), "R-Type")
{
}

UGL::~UGL()
{
	_window.close();
}

void		UGL::loadSprite(const std::string &path, const std::string &name) {
	_sprites.emplace(name, std::make_pair(std::make_shared<sf::Sprite>(), std::make_shared<sf::Texture>()));
	if (!_sprites[name].second->loadFromFile(path))
		throw std::invalid_argument("Error: Unable to load Texture " + path);
	_sprites[name].first->setTexture(*_sprites[name].second);
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

extern "C" {
	std::shared_ptr<ILib>		create_lib() {
    		return std::make_shared<UGL>();
	}
}
