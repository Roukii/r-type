//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <vector>
#include <typeindex>
#include <map>
#include <memory>
#include <functional>

#include "../../../client/Lib/include/AnimatedSprite.hpp"
#include "AComponent.hpp"
#include "../../../client/Lib/include/EntityGraphique.hpp"
#include "../../../utils/Protocol/Message.hpp"

namespace UgandaEngine {
        class Entity {
            /*
             * Variables
             */
        public:
            // Factory
            std::map<std::string, std::function<void()>> _funcComp;
            std::string _name;

            std::shared_ptr<EntityFactoryData> myGraph;

            //position
            float posX;
            float posY;

            //speed

            float speedX;
            float speedY;


            /*
             * Constructors / Destructor
             */
        public:
            Entity() = default;

            ~Entity() = default;

            /*
             * Function and methods
             */
        };
}


#endif //R_TYPE_AENTITY_HPP
