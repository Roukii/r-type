//
// Created by alex on 1/15/18.
//

#ifndef DISPLAYTESTS_SHIPPROJECTILE_HPP
#define DISPLAYTESTS_SHIPPROJECTILE_HPP

#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class ShipProjectile : public sf::Drawable {
public:
	/*
	 * CTOR & DTOR
	 */
	ShipProjectile(float, sf::Vector2f);
	~ShipProjectile() override = default;

	/*
	 * Member Functions
	 */
	void 		update();
	bool 		isDestroyed();
	void 		draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/*
	 * Member Variables
	 */
private:
	float 			_velocity;
	sf::Vector2f		_pos;
	const std::shared_ptr<sf::Texture>	_texture;
	sf::Sprite		_sprite;
	bool 			_isDestroyed;
};


#endif //DISPLAYTESTS_SHIPPROJECTILE_HPP
