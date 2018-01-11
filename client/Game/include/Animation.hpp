//
// Created by alex on 1/11/18.
//

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation {
public:
	Animation();

	void					addFrame(const sf::IntRect& rect);
	void 					setSpriteSheet(const sf::Texture& texture);
	const sf::Texture*			getSpriteSheet() const;
	std::size_t				getSize() const;
	const sf::IntRect&			getFrame(std::size_t n) const;

private:
	std::vector<sf::IntRect>	_frames;
	const sf::Texture*		_texture;
};


#endif // ANIMATION_HPP
