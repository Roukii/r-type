//
// Created by zozo on 21/01/18.
//

#include "../../server/include/RFCHandler.hpp"
#include "../include/RFCRoomHandler.hpp"

namespace RTypeClient
{
    RFCRoomHandler::RFCRoomHandler(std::shared_ptr<RTypeServer::IServerUdpSocket> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCRoomHandler::initMapOfCommandHandler()
    {

    }

    void RFCRoomHandler::executeCommand(RTypeServer::Message &msg, std::size_t ownerID)
    {
        RTypeServer::code codeCommand = (RTypeServer::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

}