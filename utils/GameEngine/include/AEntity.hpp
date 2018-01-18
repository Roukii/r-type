//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <vector>
#include <functional>
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

        //Type of the entity
        int _Type;
        int _Id;


        /*
         * Constructors / Destructor
         */

    public:
        AEntity(int type = -1, int id = -1) { _Type = type; _Id = id; }
        virtual ~AEntity() = default;


        /*
         * Function and methods
         */

    public:
        //Getters and setters
        int getType() { return _Type; }
        void setType(int newType) { _Type = newType; }


        //Add components
        void addComponent(const AComponent &component);


        /*
         * Virtual functions
         */


        //Update Entity function
        virtual void update(int type, float elapsedTime, KeyInput keyInput) = 0;
    };
}


#endif //R_TYPE_AENTITY_HPP
