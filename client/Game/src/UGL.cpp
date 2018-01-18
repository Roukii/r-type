//
// Created by alex on 1/18/18.
//

#include "UGL.hpp"

void UGL::loadSprite(const std::string &path, const std::string &name) {
	_sprites.try_emplace(name, std::make_pair(std::make_shared<sf::Sprite>(), std::make_shared<sf::Texture>()));

	if (!_sprites[name].second->loadFromFile(path))
		throw std::invalid_argument("Error: Unable to load Texture " + path);
	_sprites[name].first->setTexture(*_sprites[name].second);
}

void UGL::loadLib() {

}

void UGL::loadFont(const std::string &path) {
	if (!_font.loadFromFile(path))
		throw ("error loading font");
}

void UGL::loadText(int x, int y, int size, const std::string &str, const std::string &name) {
	_texts[name] = std::make_shared<std::string>(str);

	_texts[name]->setFont(_font);
	_texts[name]->setPosition(x, y);
	_texts[name]->setCharacterSize(size);
}

void UGL::loadSound(const std::string &path, const std::string &name) {
	_sound.try_emplace(name, std::make_pair(std::make_shared<sf::Sound>(), std::make_shared<sf::SoundBuffer>()));

	if (!_sound[name].second->loadFromFile(path))
		throw std::invalid_argument("Error: Unable to load SoundBuffer " + path);
	_sound[name].first->setBuffer(*_sound[name].second);
}

void UGL::loadMusic(const std::string &path, const std::string &name) {
	_music[name] = std::make_shared<sf::Music>();
	if (!_music[name]->openFromFile(path))
		throw std::invalid_argument("Error: Unable to load Music " + path);
}
