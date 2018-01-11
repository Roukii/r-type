//
// Created by alex on 1/11/18.
//

#ifndef DISPLAYTESTS_SHIP_HPP
#define DISPLAYTESTS_SHIP_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

#include "AnimatedSprite.hpp"

class Ship : public sf::Drawable {
public:
	enum 	Direction {
		UP = 0,
		DOWN,
		NONE
	};
	/*
	 * CTOR & DTOR
	 */
	Ship();
	~Ship() {}

	void 		update(const sf::Event&);


	virtual void 	draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	AnimatedSprite	_currentSprite;
	std::vector<Animation*>	_animations;
	Direction	_currentDirection;
	sf::Texture*	_texture;
	sf::Vector2f	_position;
	sf::Clock	_frameClock;
	sf::Time	_frameTime;
	float 		_speed;
};


#endif //DISPLAYTESTS_SHIP_HPP
