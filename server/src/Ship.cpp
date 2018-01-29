//
// Created by sentrance on 28/01/18.
//

#include "../include/Ship.hpp"

RTypeGame::Ship::Ship(unsigned long int id) : AGameEntity(id) {
    _type = RTypeGame::eType::SHIP;
}
