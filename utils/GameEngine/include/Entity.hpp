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

namespace UgandaEngine {
    class Entity {
        /*
         * Variables
         */
    public:
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

        //Moving functions. Position should have the calcul: pos += _Speed * elapsedTime.
        //Update Entity function
        //virtual void update(float elapsedTime, KeyInput keyInput) = 0;
    public:
        virtual void addComponent(std::type_index type, std::shared_ptr<AComponent> component);

        template <typename T>
        T* get() {
            auto it = _components.find(std::type_index(typeid(T)));
            if (it != _components.end())
                return dynamic_cast<T*>(it->second);
            return nullptr;
        }

        void setType(const std::string &type) { _type = type; }
        std::string getType() const { return _type; }
    };
}


#endif //R_TYPE_AENTITY_HPP
