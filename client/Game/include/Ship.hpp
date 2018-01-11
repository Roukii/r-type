//
// Created by alex on 1/11/18.
//

#ifndef DISPLAYTESTS_SHIP_HPP
#define DISPLAYTESTS_SHIP_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

class Ship : public sf::Drawable {
public:
	/*
	 * CTOR & DTOR
	 */
	Ship();
	~Ship() {}

	void 		update(const sf::Event&);


	virtual void 	draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite	_sprite;
	sf::Texture	_texture;
	sf::Vector2f	_position;
};


#endif //DISPLAYTESTS_SHIP_HPP
