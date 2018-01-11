//
// Created by alex on 1/11/18.
//

#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>

#include "Ship.hpp"

Ship::Ship() {
	if (!_texture.loadFromFile("assets/ship_1.png"))
		throw std::invalid_argument("Error: Cannot load image");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
	_sprite.setScale(8.0f, 8.0f);
	_position.x = 500;
	_position.y = 700;
	_sprite.setPosition(_position);
}

void 		Ship::update(const sf::Event& e) {
	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Up) {
			_position.y -= 1.0f;
		} else if (e.key.code == sf::Keyboard::Down) {
			_position.y += 1.0f;
		} else if (e.key.code == sf::Keyboard::Right) {
			_position.x += 1.0f;
		} else if (e.key.code == sf::Keyboard::Left) {
			_position.x -= 1.0f;
		}
	}
	_sprite.setPosition(_position);
}

void		Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}
