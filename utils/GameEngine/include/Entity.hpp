//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <vector>
#include "EngineDefinitions.hpp"
#include "AComponent.hpp"

namespace UgandaEngine {
    class Entity {
        /*
         * Variables
         */
    protected:
        //Vector d'entity

        /*
         * Constructors / Destructor
         */
        Entity() = default;
        virtual ~Entity() = default;

        /*
         * Function and methods
         */
    public:
        std::map<std::string, AComponent> _Components;

        //Moving functions. Position should have the calcul: pos += _Speed * elapsedTime.
        //Update Entity function
        virtual void update(float elapsedTime, KeyInput keyInput) = 0;

        virtual void addComponent(const AComponent &component);
    };
}


#endif //R_TYPE_AENTITY_HPP
