//
// Created by sentrance on 28/01/18.
//

#include <iostream>
#include "AGameEntity.hpp"

void RTypeGame::AGameEntity::move(double elapsedTime) {
    std::cout << "[DBG] On move Pos : " << _posX << "|" << _posY << std::endl;
    std::cout << "[DBG] Elapsed time : " << elapsedTime << "speed x.y : " << _speedX << "|" << _speedY << std::endl;
    _posX += _speedX;
    _posY += _speedY;
    if (_type == SHIP) {
        _speedX = 0;
        _speedY = 0;
    }
    std::cout << "[DBG] After move, POS : " << _posX << "|" << _posY << std::endl;
}
