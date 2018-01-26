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
    namespace entity {
        class Entity {
            /*
             * Variables
             */
        public:
            // Factory
            std::map<std::string, std::function<void(RTypeProtocol::Message&)>> _funcComp;
            std::string _name;
            std::shared_ptr<EntityFactoryData>              myGraph;

            // LUA
            std::map<std::type_index, std::shared_ptr<AComponent> > _components;
            std::string _type;

            /*
             * Constructors / Destructor
             */
        public:
            Entity() = default;

            ~Entity() = default;

            /*
             * Function and methods
             */
        public:
            virtual void addComponent(std::type_index type, std::shared_ptr<AComponent> component);

            template<typename T>
            std::shared_ptr<T> get() {
                std::map<std::type_index, std::shared_ptr<UgandaEngine::AComponent>>::iterator it = _components.find(
                        std::type_index(typeid(T)));
                std::shared_ptr<T> sharedPtr;
                if (it != _components.end()) {
                    sharedPtr = std::dynamic_pointer_cast<T>(it->second);
                    return sharedPtr;
                }
                return sharedPtr;
            }

            void setType(const std::string &type) { _type = type; }

            std::string getType() const { return _type; }
        };
    }
}


#endif //R_TYPE_AENTITY_HPP
