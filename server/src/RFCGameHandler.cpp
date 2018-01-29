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
        std::cout << "[OK] Received action from owner : " << _currentOwnerID << std::endl;
        switch (static_cast<RTypeProtocol::actions>(currentMessage._msg->data._action._action)) {
            case RTypeProtocol::actions::UP :
                std::cout << "[OK] Action is up." << std::endl;
                _game._entities[(_currentOwnerID - 1)]._speedY += 5;
                break;
            case RTypeProtocol::actions::DOWN :
                std::cout << "[OK] Action is down." << std::endl;
                _game._entities[(_currentOwnerID - 1)]._speedY -= 5;
                break;
            case RTypeProtocol::actions::LEFT :
                std::cout << "[OK] Action is left." << std::endl;
                _game._entities[(_currentOwnerID - 1)]._speedX -= 5;
                break;
            case RTypeProtocol::actions::RIGHT :
                std::cout << "[OK] Action is right." << std::endl;
                _game._entities[(_currentOwnerID - 1)]._speedX += 5;
                break;
            default:
                break;
        }
    }
}