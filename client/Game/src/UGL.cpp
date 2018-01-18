//
// Created by alex on 1/18/18.
//

#include "UGL.hpp"

sf::Sprite		UGL::loadSprite(const std::string& filePath) {
	_textures.emplace_back(std::make_shared<sf::Texture>());
	if (!_textures.back()->loadFromFile(filePath))
		throw std::invalid_argument("Error: Unable to load texture from " + filePath);

	return sf::Sprite(*_textures.back());
}
