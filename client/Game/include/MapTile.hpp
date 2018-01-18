//
// Created by alex on 1/17/18.
//

#ifndef DISPLAYTESTS_MAPTILE_HPP
#define DISPLAYTESTS_MAPTILE_HPP

#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

struct MapTile {
	//std::string	_texture;
	int		_id;
	bool		_isWalkable;
	bool		_isEvent;
	std::shared_ptr<sf::Texture>	_texture;
	sf::Sprite	_sprite;
};

#endif //DISPLAYTESTS_MAPTILE_HPP
