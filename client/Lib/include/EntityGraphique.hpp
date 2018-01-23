//
// Created by youssef on 21/01/18.
//

#ifndef R_TYPE_ENTITYGRAPHIQUE_HPP
#define R_TYPE_ENTITYGRAPHIQUE_HPP

#include <memory>
#include <utility>
#include <SFML/Graphics/Texture.hpp>

#include "Animation.hpp"

class EntityFactoryData {
public:
    EntityFactoryData(std::shared_ptr<sf::Texture> texture, std::vector<std::shared_ptr<Animation>> anims)
             {
                 _texture = texture;
                 _anims = anims;
             }
    std::shared_ptr<sf::Texture>	_texture;
    std::vector<std::shared_ptr<Animation>>	_anims;
};

#endif //R_TYPE_ENTITYGRAPHIQUE_HPP
