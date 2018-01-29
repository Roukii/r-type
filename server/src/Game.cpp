//
// Created by sentrance on 26/01/18.
//

#include "GameEFunc.hpp"
#include "include/MapConfHandler.hpp"
#include "Game.hpp"
#include "Message.hpp"

void RTypeGame::Game::init(const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room) {
    for (int i = 0; i < _nbrPlayers; i++) {
        Ship newPlayer = createNewPlayer();
        _entities.push_back(newPlayer);
        room.get()->SendToAll(createMsgNewE(newPlayer, RTypeProtocol::SHIP));
        std::cout << "[OK] Created new player with id : " << newPlayer._id << std::endl;
    }
}

void RTypeGame::Game::play(double elapsedTime, const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room) {
    std::cout << "Total of entities : " << _entities.size() << std::endl;
    for (auto entity = _entities.begin(); entity != _entities.end(); ++entity) {
        RTypeProtocol::Message msg;
        entity->move(elapsedTime);
        if (checkOutOfBound(*entity)) {
            msg = createMsgDelE(entity->_id);
        } else {
            msg = createMsgMoveE(*entity);
//            for (auto collision = _entities.begin(); collision != _entities.end(); ++collision) {
//                if (checkCollision(*entity, *collision) && entity->_id != collision->_id) {
//                    room.get()->SendToAll(createMsgDelE(collision->_id));
//                    msg = createMsgDelE(entity->_id);
//                    std::cout << "Erasing id : " << collision->_id << std::endl;
//                    _entities.erase(collision);
//                    --entity;
//                    std::cout << "Erasing id : " << entity->_id << std::endl;
//                    _entities.erase(entity);
//                    --entity;
//                    room.get()->SendToAll(msg);
//                    break;
//                }
//            }
        }
        room.get()->SendToAll(msg);
    }

    if (_ticks == 1) {
        Ship ennemy = createNewEnnemy();
        std::cout << "Ennemy pos:" << ennemy._posX << "|" << ennemy._posY << std::endl;
        _entities.push_back(ennemy);
        room.get()->SendToAll(createMsgNewE(ennemy, RTypeProtocol::ENNEMY));
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
    std::cout << "[OK] Deleted entity : " << id << std::endl;
    RTypeProtocol::Message currentMessage;
    currentMessage._msg.get()->_header._code = RTypeProtocol::DEL_ENTITY;
    union
    {
        char ch[4];
        int nb;
    } char2int;
    char2int.nb = id;
    currentMessage._msg.get()->data._entity.id[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity.id[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity.id[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity.id[3] = char2int.ch[3];

    return currentMessage;
}

RTypeProtocol::Message RTypeGame::Game::createMsgMoveE(AGameEntity gameEntity) {
    std::cout << "[OK] Moved entity : " << gameEntity._id  << " at positions : " << gameEntity._posX << "|" << gameEntity._posY << std::endl;
    RTypeProtocol::Message currentMessage;
    currentMessage._msg.get()->_header._code = RTypeProtocol::MOV_ENTITY;
    union
    {
        char ch[4];
        int nb;
    } char2int;
    char2int.nb = gameEntity._id;
    currentMessage._msg.get()->data._entity.id[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity.id[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity.id[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity.id[3] = char2int.ch[3];

    char2int.nb = gameEntity._posX;
    currentMessage._msg.get()->data._entity._pos._x[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity._pos._x[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity._pos._x[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity._pos._x[3] = char2int.ch[3];

    char2int.nb = gameEntity._posY;
    currentMessage._msg.get()->data._entity._pos._y[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity._pos._y[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity._pos._y[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity._pos._y[3] = char2int.ch[3];

    return currentMessage;
}

RTypeProtocol::Message RTypeGame::Game::createMsgNewE(AGameEntity gameEntity, RTypeProtocol::types type) {
    std::cout << "[OK] New entity id : " << gameEntity._id << std::endl;
    RTypeProtocol::Message currentMessage;
    currentMessage._msg.get()->_header._code = RTypeProtocol::NEW_ENTITY;
    union
    {
        char ch[4];
        int nb;
    } char2int;
    char2int.nb = gameEntity._id;
    currentMessage._msg.get()->data._entity.id[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity.id[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity.id[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity.id[3] = char2int.ch[3];

    char2int.nb = gameEntity._posX;
    currentMessage._msg.get()->data._entity._pos._x[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity._pos._x[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity._pos._x[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity._pos._x[3] = char2int.ch[3];

    char2int.nb = gameEntity._posY;
    currentMessage._msg.get()->data._entity._pos._y[0] = char2int.ch[0];
    currentMessage._msg.get()->data._entity._pos._y[1] = char2int.ch[1];
    currentMessage._msg.get()->data._entity._pos._y[2] = char2int.ch[2];
    currentMessage._msg.get()->data._entity._pos._y[3] = char2int.ch[3];

    currentMessage._msg.get()->data._entity.type = type;

    return currentMessage;
}

RTypeGame::Ship RTypeGame::Game::createNewEnnemy() {
    Ship newEnnemy(static_cast<int>(_entities.size()));
    newEnnemy._id = static_cast<int>(_entities.size());
    newEnnemy._posX = 800;
    newEnnemy._posY = 800;
    newEnnemy._speedX = -20;
    newEnnemy._speedY = 0;
    newEnnemy._height = 20;
    newEnnemy._width = 46;
    return newEnnemy;
}

RTypeGame::Ship RTypeGame::Game::createNewPlayer() {
    Ship newPlayer(static_cast<int>(_entities.size()));
    newPlayer._id = static_cast<int>(_entities.size());
    newPlayer._posX = 100;
    newPlayer._posY = 100;
    newPlayer._speedX = 0;
    newPlayer._speedY = 0;
    newPlayer._height = 40;
    newPlayer._width = 92;
    return newPlayer;
}
