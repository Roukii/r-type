//
// Created by zozo on 21/01/18.
//

#include "../../server/include/RFCHandler.hpp"
#include "../include/RFCRoomHandler.hpp"

namespace RTypeClient
{
    RFCRoomHandler::RFCRoomHandler(std::shared_ptr<IClientUdpSocket> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCRoomHandler::initMapOfCommandHandler()
    {

    }

    void RFCRoomHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        auto codeCommand = static_cast<RTypeProtocol::code>(msg._msg->_header._code);
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

}