//
// Created by zozo on 21/01/18.
//

#include "../../server/include/RFCHandler.hpp"
#include "../include/RFCRoomHandler.hpp"

namespace RTypeClient
{
    RFCRoomHandler::RFCRoomHandler(IClientUdpSocket &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCRoomHandler::initMapOfCommandHandler()
    {

    }

    void RFCRoomHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

}