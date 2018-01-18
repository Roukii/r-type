//
// Created by alex on 1/11/18.
//

#ifndef DISPLAYTESTS_SHIP_HPP
#define DISPLAYTESTS_SHIP_HPP

#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <list>

#include "AnimatedSprite.hpp"
#include "ShipProjectile.hpp"

// TODO: Replace by smart pointers!!!

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
	~Ship() override = default;

	void 		update(const sf::Event&);
	void 		draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	AnimatedSprite	_currentSprite;
	std::vector<Animation*>	_animations;
	Direction	_currentDirection;
	sf::Texture*	_texture;
	sf::Vector2f	_position;
	sf::Clock	_frameClock;
	sf::Time	_frameTime;
	float 		_speed;
	std::list<ShipProjectile>	_missiles;
};


#endif //DISPLAYTESTS_SHIP_HPP
