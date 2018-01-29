//
// Created by sentrance on 28/01/18.
//

#ifndef R_TYPE_COLLISIONS_HPP
#define R_TYPE_COLLISIONS_HPP


#include "Entity.hpp"

namespace RTypeGame {
    struct GameEFunc {
        static bool checkCollision(const UgandaEngine::Entity &entity1, const UgandaEngine::Entity &entity2);
        static void move(UgandaEngine::Entity &entity, double timeElapsed);
        static void shoot();
    };
}


#endif //R_TYPE_COLLISIONS_HPP
