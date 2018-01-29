//
// Created by alex on 1/11/18.
//

#ifndef ANIMATEDSPRITE_HPP
#define ANIMATEDSPRITE_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>

#include "Animation.hpp"

class AnimatedSprite : public sf::Drawable, public sf::Transformable {
public:
	AnimatedSprite(sf::Time frameTime = sf::seconds(0.1f), bool paused = false, bool looped = true);

	void		update(sf::Time deltaTime);
	void		setAnimation(const std::shared_ptr<Animation> animation);
	void		setFrameTime(sf::Time time);
	void		play();
	void		play(std::shared_ptr<Animation> animation);
	void		pause();
	void		stop();
	void		setLooped(bool looped);
	void		setColor(const sf::Color& color);
	const std::shared_ptr<Animation>	getAnimation() const;
	sf::FloatRect	getLocalBounds() const;
	sf::FloatRect	getGlobalBounds() const;
	bool		isLooped() const;
	bool		isPlaying() const;
	sf::Time	getFrameTime() const;
	void		setFrame(std::size_t newFrame, bool resetTime = true);

	void		draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::shared_ptr<Animation>	_animation;
	sf::Time		_frameTime;
	sf::Time		_currentTime;
	std::size_t		_currentFrame;
	bool			_isPaused;
	bool			_isLooped;
	std::shared_ptr<sf::Texture>	_texture;
	sf::Vertex		_vertices[4];


};


#endif // ANIMATEDSPRITE_HPP
