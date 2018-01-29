//
// Created by sentrance on 28/01/18.
//

#include <iostream>
#include "AGameEntity.hpp"

void RTypeGame::AGameEntity::move(double elapsedTime) {
    _posX += (elapsedTime * _speedX);
    _posY += (elapsedTime * _speedY);
}
