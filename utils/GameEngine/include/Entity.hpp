//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <vector>
#include <typeindex>
#include <map>
#include <memory>
#include "AComponent.hpp"
#include "TestComponent.hpp"

namespace UgandaEngine {
    class Entity {
        /*
         * Variables
         */
    public:
        // LUA
        std::map<std::type_index, std::shared_ptr<AComponent> > _components;

        // Factory
        std::map<std::string, std::function<void()>> func_comp;

        //LUA
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

        template <typename T>
        std::shared_ptr<T> get() {
            std::map<std::type_index, std::shared_ptr<UgandaEngine::AComponent>>::iterator it = _components.find(std::type_index(typeid(T)));
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


#endif //R_TYPE_AENTITY_HPP
