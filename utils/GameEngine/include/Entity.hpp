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
            std::shared_ptr<EntityFactoryData> _myGraph;
            std::string     name;
            // Position
            int _posX;
            int _posY;

            // Speed
            float _speedX;
            float _speedY;

            // Size
            int _width;
            int _height;

            /*
             * Constructors / Destructor
             */
        public:
            Entity() = default;
            virtual ~Entity() = default;
        };
}


#endif //R_TYPE_AENTITY_HPP
