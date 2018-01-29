//
// Created by sentrance on 26/01/18.
//

#include "GameEFunc.hpp"
#include "include/MapConfHandler.hpp"
#include "Game.hpp"
#include "Message.hpp"

void RTypeGame::Game::init(const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room) {
    _room = room;
    for (int i = 0; i < _nbrPlayers; i++) {
        Ship newPlayer = createNewPlayer();
        _entities.push_back(newPlayer);
        room.get()->SendToAll(createMsgNewE(newPlayer, RTypeProtocol::SHIP));
    }
}

void RTypeGame::Game::play(double elapsedTime, const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room) {
    for (auto entity = _entities.begin(); entity != _entities.end(); ++entity) {
        if (!entity->_removable) {
            RTypeProtocol::Message msg;
            int prevX = entity->_posX;
            int prevY = entity->_posY;
            entity->move(elapsedTime);
            if (checkOutOfBound(*entity)) {
                if (entity->_type == SHIP) {
                    entity->_posX = prevX;
                    entity->_posY = prevY;
                } else {
                    msg = createMsgDelE(entity->_id);
                    entity->_removable = true;
                }
            } else {
                msg = createMsgMoveE(*entity);
                for (auto collision = _entities.begin(); collision != _entities.end(); ++collision) {
                    if (checkCollision(*entity, *collision) && entity->_id != collision->_id && !entity->_removable) {
                        std::cout << "[DBG] COLLISION!!" << std::endl;
                        room.get()->SendToAll(createMsgDelE(collision->_id));
                        msg = createMsgDelE(entity->_id);
                        entity->_removable = true;
                        collision->_removable = true;
                        break;
                    }
                }
            }
            room.get()->SendToAll(msg);
        }
    }

    _entities.erase(
            std::remove_if(_entities.begin(), _entities.end(),
            [](const AGameEntity &e) { return e._removable; }),
            _entities.end());

    if (_ticks == 1) {
        Ship ennemy = createNewEnnemy();
        _entities.push_back(ennemy);
        room.get()->SendToAll(createMsgNewE(ennemy, RTypeProtocol::ENNEMY));
    }
}

bool RTypeGame::Game::checkCollision(const RTypeGame::AGameEntity &entity1, const RTypeGame::AGameEntity &entity2) {
    std::cout << "[DBG] Pos e1: " << entity1._posX << "." << entity1._posY << std::endl;
    std::cout << "[DBG] Pos e2: " << entity2._posX << "." << entity2._posY << std::endl;
    return entity1._posX < entity2._posX + entity2._width
           && entity1._posX + entity1._width > entity2._posX
           && entity1._posY < entity2._posY + entity2._height
           && entity1._height + entity1._posY > entity2._posY;
}

bool RTypeGame::Game::checkOutOfBound(const RTypeGame::AGameEntity &entity) {
    return entity._posX < 0 || (entity._posX + entity._width) > 1920 || entity._posY < 0 || (entity._posY + entity._height) > 1080;
}

RTypeProtocol::Message RTypeGame::Game::createMsgDelE(int id) {
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
    Ship newEnnemy(_nextId);
    newEnnemy._id = _nextId;
    ++_nextId;
    newEnnemy._type = RTypeGame::eType::ENNEMY;
    newEnnemy._posX = 800;
    newEnnemy._posY = 800;
    newEnnemy._speedX = -5;
    newEnnemy._speedY = 0;
    newEnnemy._height = 20;
    newEnnemy._width = 46;
    return newEnnemy;
}

RTypeGame::Ship RTypeGame::Game::createNewPlayer() {
    Ship newPlayer(_nextId);
    newPlayer._id = _nextId;
    ++_nextId;
    newPlayer._posX = 100;
    newPlayer._posY = 100;
    newPlayer._speedX = 0;
    newPlayer._speedY = 0;
    newPlayer._height = 40;
    newPlayer._width = 92;
    return newPlayer;
}

RTypeGame::Bullet RTypeGame::Game::createNewBullet(const AGameEntity &entity) {
    Bullet newBullet(_nextId);
    newBullet._id = _nextId;
    ++_nextId;
    newBullet._posY = entity._posY + (entity._height / 2);
    newBullet._height = 3;
    newBullet._width = 33;
    switch (entity._type) {
        case SHIP:
            newBullet._posX = entity._posX + (entity._width + 5);
            newBullet._speedX = 10;
            newBullet._speedY = 0;
            break;
        default:
            newBullet._posX = entity._posX - 5;
            newBullet._speedX = -10;
            newBullet._speedY = 0;
            break;
    }
    _room.get()->SendToAll(createMsgNewE(newBullet, RTypeProtocol::BULLET));
    return newBullet;
}
