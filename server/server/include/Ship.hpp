//
// Created by sentrance on 28/01/18.
//

#ifndef R_TYPE_SHIP_HPP
#define R_TYPE_SHIP_HPP


#include "AGameEntity.hpp"

namespace RTypeGame {
    class Ship : public AGameEntity {
        /*
         * Constructor and destructor
         */
    public:
        Ship(int id);

        ~Ship() = default;
    };
}


#endif //R_TYPE_SHIP_HPP
