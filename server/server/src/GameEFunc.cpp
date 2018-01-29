//
// Created by sentrance on 28/01/18.
//

#include "GameEFunc.hpp"

bool RTypeGame::GameEFunc::checkCollision(const UgandaEngine::Entity &entity1, const UgandaEngine::Entity &entity2) {
    return entity1._posX < entity2._posX + entity2._width
           && entity1._posX + entity1._width > entity2._posX
           && entity1._posY < entity2._posY + entity2._height
           && entity1._height + entity1._posY > entity1._posY;
}

void RTypeGame::GameEFunc::move(UgandaEngine::Entity &entity, double timeElapsed) {
    entity._posX += (timeElapsed * entity._speedX);
    entity._posY += (timeElapsed * entity._speedY);
}
