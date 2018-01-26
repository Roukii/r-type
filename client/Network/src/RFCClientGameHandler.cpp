//
// Created by zozo on 23/01/18.
//

#include "RFCClientGameHandler.hpp"

namespace RTypeClient
{
    RFCClientGameHandler::RFCClientGameHandler(IClientUdpSocket &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCClientGameHandler::initMapOfCommandHandler()
    {

    }

    void RFCClientGameHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }
}