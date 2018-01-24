//
// Created by zozo on 23/01/18.
//

#include "RFCClientHandler.hpp"

namespace RTypeClient
{
    RFCClientHandler::RFCClientHandler(IClientUdpSocket<RTypeProtocol::Message> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCClientHandler::initMapOfCommandHandler()
    {

    }

    void RFCClientHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

}