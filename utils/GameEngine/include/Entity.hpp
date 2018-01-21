//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <vector>
#include <typeindex>
#include <map>
#include <memory>
#include <AnimatedSprite.hpp>
#include <functional>
#include "AComponent.hpp"

namespace UgandaEngine {
    namespace entity {
        enum Direction
        {
            UP = 0,
            DOWN,
            NONE
        };
        class Entity {
            /*
             * Variables
             */
        public:
            std::string                                     _name;
            // LUA
            std::map<std::type_index, std::shared_ptr<AComponent> > _components;

            // Factory
            std::map<std::string, std::function<void()>>    _funcComp;

            //LUA
            std::string                                     _type;


            // créeer une classe graphique pour les entity
            // GraphEnt qui va contenir AnimatedSprite / Texture / vector<Animation>
            AnimatedSprite                                  _currentSprite;
            std::shared_ptr<sf::Texture>                    _texture;
            std::vector<std::shared_ptr<Animation>>         _animations;


            // les éléments de maniabilité
            Direction                                       _currentDirection;
            sf::Vector2f                                    _position;
            float                                           _speed;

            // les éléments rataché
            std::vector<Entity>                             _missiles;

            // TODO : position(vec2d) / vitesse(vec2d) / direction(enum)
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
                std::shared_ptr<T> hey;
                if (it != _components.end()) {
                    hey = std::dynamic_pointer_cast<T>(it->second);
                    return hey;
                }
                return hey;
            }

            void setType(const std::string &type) { _type = type; }

            std::string getType() const { return _type; }
        };
    }
}


#endif //R_TYPE_AENTITY_HPP
