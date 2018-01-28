//
// Created by sentrance on 28/01/18.
//

#include "../include/Bullet.hpp"

RTypeGame::Bullet::Bullet(int id) : AGameEntity(id) {
    _type = RTypeGame::eType::BULLET;
}
