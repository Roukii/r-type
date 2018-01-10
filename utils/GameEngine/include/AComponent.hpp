//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_ACOMPONENT_HPP
#define R_TYPE_ACOMPONENT_HPP

#include "EngineDefinitions.hpp"

namespace UgandaEngine {
    class AComponent {
        /*
         * Variables
         */
        int id;
        ComponentType  _ComponentType;

        /*
         * Constructor and destructor
         */
    protected:
        AComponent(int id = -1, ComponentType componentType = DEFAULT) = default;
        virtual ~AComponent() = default;

        /*
         * Function and methods
         */
        //TODO: a update func?
        void update();
    };
}


#endif //R_TYPE_ACOMPONENT_HPP