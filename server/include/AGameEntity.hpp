//
// Created by sentrance on 28/01/18.
//

#ifndef R_TYPE_GAMEENTITY_HPP
#define R_TYPE_GAMEENTITY_HPP

#include "Entity.hpp"

namespace RTypeGame {
    typedef enum EntityType {
        UNKNOWN,
        SHIP,
        ENNEMY,
        BULLET
    } eType;

    class AGameEntity : public UgandaEngine::Entity {
        /*
         * Variables
         */
    public:
        eType _type;
        unsigned long int _id;
        bool _removable;

        /*
         * Constructor and destructor
         */
    public:
        AGameEntity(unsigned long int id) : _type(UNKNOWN), _id(id), _removable(false) {}
        ~AGameEntity() override = default;

        /*
         * Functions and methods
         */
    public:
        virtual void move(double elapsedTime);
    };
}


#endif //R_TYPE_GAMEENTITY_HPP
