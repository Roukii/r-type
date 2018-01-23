//
// Created by zozo on 23/01/18.
//

#include "../include/RFCGameHandler.hpp"

namespace RTypeServer {
    RFCGameHandler::RFCGameHandler(std::shared_ptr<IServerUdpSocket> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCGameHandler::initMapOfCommandHandler()
    {
        
    }

    void RFCGameHandler::executeCommand(Message &msg, std::size_t ownerID) {
        code codeCommand = (code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end()) {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }
}