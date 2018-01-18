//
// Created by alex on 1/18/18.
//

#ifndef DISPLAYTESTS_UGL_HPP
#define DISPLAYTESTS_UGL_HPP

// UGL means Uganda Graphic Library

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class UGL {
public:
	UGL() = default;
	~UGL() = default;

	//Todo: function creating and loading sprites sprites
	sf::Sprite		loadSprite(const std::string&);
	void 			setSpriteScale(sf::Sprite& sprite, sf::Vector2f& size) { sprite.setScale(size); }
	void 			setSpritePosition(sf::Sprite& sprite, sf::Vector2f& size) { sprite.setPosition(size); }
	void 			drawSprite(sf::Sprite& sprite) { _window.draw(sprite); }
	//Todo: function handling sound

private:
	sf::RenderWindow	_window;
	std::vector<std::shared_ptr<sf::Texture>>	_textures;
};


#endif /* DISPLAYTESTS_UGL_HPP */
