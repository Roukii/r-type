//
// Created by zozo on 23/01/18.
//

#include "../include/RFCClientGameHandler.hpp"

namespace RTypeClient
{
    RFCClientGameHandler::RFCClientGameHandler(std::shared_ptr<RTypeServer::IServerUdpSocket> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCClientGameHandler::initMapOfCommandHandler()
    {

    }

    void RFCClientGameHandler::executeCommand(RTypeServer::Message &msg, std::size_t ownerID)
    {
        RTypeServer::code codeCommand = (RTypeServer::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }
}