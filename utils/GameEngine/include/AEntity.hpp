//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include "EngineDefinitions.hpp"

namespace UgandaEngine {
    class AEntity {
        /*
         * Variables
         */
    protected:
        //Entity hurt or/and can be hurt
        bool _doesDamage;
        bool _takeDamage;

        //Speed
        float _Speed;

        /*
         * Constructors / Destructor
         */
        AEntity() : _Speed(0), _doesDamage(false), _takeDamage(false) {};
        virtual ~AEntity() = default;

        /*
         * Function and methods
         */
    public:
        //Getters and setters
        bool doesDamage() { return _takeDamage; }
        bool takeDamage() { return _doesDamage; }

        //Moving functions. Position should have the calcul: pos += _Speed * elapsedTime.
        //Update Entity function
        virtual void update(float elapsedTime, KeyInput keyInput) = 0;
    };
}


#endif //R_TYPE_AENTITY_HPP
