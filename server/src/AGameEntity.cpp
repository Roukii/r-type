//
// Created by sentrance on 28/01/18.
//

#include <iostream>
#include "AGameEntity.hpp"

void RTypeGame::AGameEntity::move(double elapsedTime) {
    _posX += _speedX;
    _posY += _speedY;
    if (_type == SHIP) {
        _speedX = 0;
        _speedY = 0;
    }
}
