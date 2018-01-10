//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <vector>
#include "EngineDefinitions.hpp"
#include "AComponent.hpp"

namespace UgandaEngine {
    class AEntity {
        /*
         * Variables
         */
    protected:
        //Vector d'entity
        std::vector<AComponent> _Components;

        /*
         * Constructors / Destructor
         */
        AEntity() = default;
        virtual ~AEntity() = default;

        /*
         * Function and methods
         */
    public:
        //Moving functions. Position should have the calcul: pos += _Speed * elapsedTime.
        //Update Entity function
        virtual void update(float elapsedTime, KeyInput keyInput) = 0;

        virtual void addComponent(const AComponent &component);
    };
}


#endif //R_TYPE_AENTITY_HPP
