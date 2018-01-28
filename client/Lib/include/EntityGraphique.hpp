//
// Created by youssef on 21/01/18.
//

#ifndef R_TYPE_ENTITYGRAPHIQUE_HPP
#define R_TYPE_ENTITYGRAPHIQUE_HPP

#include <memory>
#include <utility>
#include <SFML/Graphics/Texture.hpp>

#include "AnimatedSprite.hpp"
//#include "Animation.hpp"
//#include "UGL.hpp"

class EntityFactoryData {
public:
	EntityFactoryData(std::shared_ptr<sf::Texture> texture, std::vector<std::shared_ptr<Animation>> anims)
	{
		_texture = std::move(texture);
		_anims = std::move(anims);
	}
	std::shared_ptr<sf::Texture>	        _texture;
	std::vector<std::shared_ptr<Animation>>	_anims;
	AnimatedSprite				_currentSprite;

};

#endif //R_TYPE_ENTITYGRAPHIQUE_HPP
