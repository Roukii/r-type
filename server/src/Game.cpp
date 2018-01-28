//
// Created by sentrance on 26/01/18.
//

#include "GameEFunc.hpp"
#include "include/MapConfHandler.hpp"
#include "Game.hpp"
#include "Message.hpp"

void RTypeGame::Game::init() {
    // TODO: création des players
}

void RTypeGame::Game::play(double elapsedTime, const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room) {
    for (RTypeGame::AGameEntity &entity : _entities) {
        RTypeProtocol::Message msg;
        entity.move(elapsedTime);
        if (checkOutOfBound(entity)) {
            msg = createMsgDelE(entity._id);
        } else {
            msg = createMsgMoveE(entity._id);
            for (const RTypeGame::AGameEntity &collision : _entities) {
                if (checkCollision(entity, collision)) {
                    room.get()->SendToAll(createMsgDelE(collision._id));
                    msg = createMsgDelE(entity._id);
                    break;
                }
            }
        }
        room.get()->SendToAll(msg);
    }

    if (_ticks == 300) {
        Ship ennemy = createNewEnnemy();
        std::cout << "Ennemy pos:" << ennemy._posX << "|" << ennemy._posY << std::endl;
        _entities.push_back(ennemy);
        //TODO: changer en ennemi
        room.get()->SendToAll(createMsgNewE(ennemy._id, RTypeProtocol::SHIP));
    }
}

bool RTypeGame::Game::checkCollision(const RTypeGame::AGameEntity &entity1, const RTypeGame::AGameEntity &entity2) {
    return entity1._posX < entity2._posX + entity2._width
           && entity1._posX + entity1._width > entity2._posX
           && entity1._posY < entity2._posY + entity2._height
           && entity1._height + entity1._posY > entity1._posY;
}

bool RTypeGame::Game::checkOutOfBound(const RTypeGame::AGameEntity &entity) {
    return entity._posX < 0 || entity._posX > 1920 || entity._posY < 0 || entity._posY > 1080;
}

RTypeProtocol::Message RTypeGame::Game::createMsgDelE(int id) {
    RTypeProtocol::Message currentMessage;
    currentMessage._msg.get()->_header._code = RTypeProtocol::DEL_ENTITY;
    union
    {
        char ch[4];
        int nb;
    } char2int;
    char2int.nb = id;// ton id de merde
    currentMessage._msg.get()->data._entity.id[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity.id[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity.id[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity.id[3] = char2int.ch[3];
    return currentMessage;
}

RTypeProtocol::Message RTypeGame::Game::createMsgMoveE(int id) {
    RTypeProtocol::Message currentMessage;
    currentMessage._msg.get()->_header._code = RTypeProtocol::MOV_ENTITY;
    union
    {
        char ch[4];
        int nb;
    } char2int;
    char2int.nb = id;// ton id de merde
    currentMessage._msg.get()->data._entity.id[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity.id[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity.id[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity.id[3] = char2int.ch[3];
    return currentMessage;
}

RTypeProtocol::Message RTypeGame::Game::createMsgNewE(int id, RTypeProtocol::types type) {
    RTypeProtocol::Message currentMessage;
    currentMessage._msg.get()->_header._code = RTypeProtocol::NEW_ENTITY;
    union
    {
        char ch[4];
        int nb;
    } char2int;
    char2int.nb = id;// ton id de merde
    currentMessage._msg.get()->data._entity.id[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity.id[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity.id[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity.id[3] = char2int.ch[3];
    currentMessage._msg.get()->data._entity.type = type;

    return currentMessage;
}

RTypeGame::Ship RTypeGame::Game::createNewEnnemy() {
    Ship newEnnemy(static_cast<int>(_entities.size()));
    newEnnemy._id = static_cast<int>(_entities.size());
    newEnnemy._posX = 800;
    newEnnemy._posY = 800;
    newEnnemy._speedX = -5;
    newEnnemy._speedY = 0;
    newEnnemy._height = 20;
    newEnnemy._width = 46;
    return newEnnemy;
}
