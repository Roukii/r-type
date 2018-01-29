//
// Created by zozo on 23/01/18.
//

#include <iostream>
#include "RFCGameHandler.hpp"

namespace RTypeServer {
    RFCGameHandler::RFCGameHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket,
                                   RTypeGame::Game &game) : _socket(socket), _game(game)
    {
        initMapOfCommandHandler();
    }

    void RFCGameHandler::initMapOfCommandHandler()
    {
        _CommandHandler.insert({RTypeProtocol::ACTION, &RFCGameHandler::RFCAction});
    }

    void RFCGameHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = static_cast<RTypeProtocol::code>(msg._msg->_header._code);
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end()) {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
        }
    }

    void RFCGameHandler::RFCAction(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID) {
        switch (static_cast<RTypeProtocol::actions>(currentMessage._msg->data._action._action)) {
            case RTypeProtocol::actions::UP :
                _game._entities[(_currentOwnerID - 1)]._speedY = -7;
                break;
            case RTypeProtocol::actions::DOWN :
                _game._entities[(_currentOwnerID - 1)]._speedY = 7;
                break;
            case RTypeProtocol::actions::LEFT :
                _game._entities[(_currentOwnerID - 1)]._speedX = -7;
                break;
            case RTypeProtocol::actions::RIGHT :
                _game._entities[(_currentOwnerID - 1)]._speedX = 7;
                break;
            case RTypeProtocol::actions::SHOOT :
                _game._entities.push_back(_game.createNewBullet(_game._entities[(_currentOwnerID - 1)]));
                break;
            default:
                break;
        }
    }
}