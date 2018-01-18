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

    private:
        //Type of the entity
        int _Type;


        /*
         * Constructor and destructor
         */

    public:
        AComponent(int type = -1) { _Type = type; }
        virtual ~AComponent() = default;


        /*
         * Function and methods
         */
    public:
        //Getters and setters
        int getType() { return _Type; }
        void setType(int newType) { _Type = newType; }
    };
}


#endif //R_TYPE_ACOMPONENT_HPP