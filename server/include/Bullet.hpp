//
// Created by sentrance on 28/01/18.
//

#ifndef R_TYPE_BULLET_HPP
#define R_TYPE_BULLET_HPP


#include "AGameEntity.hpp"

namespace RTypeGame {
    class Bullet : public AGameEntity {
        /*
         * Constructor and destructor
         */
    public:
        Bullet(unsigned long int id);

        ~Bullet() = default;
    };
}


#endif //R_TYPE_BULLET_HPP
