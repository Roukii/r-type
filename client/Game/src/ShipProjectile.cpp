//
// Created by alex on 1/15/18.
//

#include <iostream>
#include "ShipProjectile.hpp"

ShipProjectile::ShipProjectile(float vel, sf::Vector2f pos)
	: _velocity(vel), _pos(pos), _texture(std::make_shared<sf::Texture>()), _isDestroyed(false) {
	if (!_texture->loadFromFile("assets/ship_1.png"))
		throw std::invalid_argument("Error: Cannot load image");
	_sprite.setTexture(*_texture);
	_sprite.setTextureRect(sf::IntRect(104, 73, 33, 3));
}

void 		ShipProjectile::update() {
	_pos.x += _velocity;
	if (_pos.x > 1920)
		_isDestroyed = true;
	_sprite.setPosition(_pos);
}

bool 		ShipProjectile::isDestroyed() {
	return _isDestroyed;
}

void		ShipProjectile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}