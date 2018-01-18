//
// Created by alex on 1/11/18.
//

#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>
#include <iostream>

#include "Ship.hpp"

Ship::Ship() : _currentDirection(NONE), _speed(8.0f) {
	_texture = new sf::Texture;
	if (!_texture->loadFromFile("assets/ship_1.png"))
		throw std::invalid_argument("Error: Cannot load image");

	_animations.emplace_back(new Animation);
	_animations.emplace_back(new Animation);
	_animations.emplace_back(new Animation);

	// UP ANIM
	_animations[UP]->setSpriteSheet(*_texture);
	_animations[UP]->addFrame(sf::IntRect(85, 14, 23, 10));
	_animations[UP]->addFrame(sf::IntRect(60, 14, 22, 10));
	_animations[UP]->addFrame(sf::IntRect(34, 12, 23, 13));
	_animations[UP]->addFrame(sf::IntRect(8, 11, 23, 15));

	// DOWN ANIM
	_animations[DOWN]->setSpriteSheet(*_texture);
	_animations[DOWN]->addFrame(sf::IntRect(137, 14, 23, 10));
	_animations[DOWN]->addFrame(sf::IntRect(163, 15, 23, 10));
	_animations[DOWN]->addFrame(sf::IntRect(189, 12, 22, 13));
	_animations[DOWN]->addFrame(sf::IntRect(214, 11, 23, 15));

	_animations[NONE]->setSpriteSheet(*_texture);
	_animations[NONE]->addFrame(sf::IntRect(111, 13, 23, 11));


	_currentSprite.setScale(4.0f, 4.0f);
	_position.x = 200;
	_position.y = 300;
	_currentSprite.setPosition(_position);
	_currentSprite.setLooped(false);
}

void 		Ship::update(const sf::Event& e) {
	_frameTime = _frameClock.restart();
	Animation*	currentAnim = _animations[NONE];
	//if (e.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			currentAnim = _animations[UP];
			_position.y -= _speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			currentAnim = _animations[DOWN];
			_position.y += _speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			_position.x += _speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			_position.x -= _speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << "Instanciation of projectile" << std::endl;
			_missiles.emplace_back(_speed + 1.0f, sf::Vector2(_position.x + 90.f, _position.y + 23.f));
		}
	/*} else
		currentAnim = _animations[NONE];*/

	/*if (e.type == sf::Event::KeyReleased) {
		switch (e.key.code) {
			case sf::Keyboard::Space:
				std::cout << "Instanciation of projectile" << std::endl;
				_missiles.emplace_back(_speed + 1.0f, sf::Vector2(_position.x + 90.f, _position.y + 23.f));
			default:
				break;
		}
	}*/

	for (auto it = _missiles.begin(); it != _missiles.end(); ++it) {
		if (it->isDestroyed()) {
			_missiles.erase(it);
			it = _missiles.begin();
		}
		else
			it->update();
	}

	_currentSprite.setPosition(_position);
	_currentSprite.update(_frameTime);
	_currentSprite.play(*currentAnim);
}

void		Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_currentSprite, states);
	for (auto& item : _missiles) {
		item.draw(target, states);
	}
}
