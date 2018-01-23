//
// Created by zozo on 23/01/18.
//

#include "RFCServerRoomHandler.hpp"

namespace RTypeServer
{
    RFCServerRoomHandler::RFCServerRoomHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCServerRoomHandler::initMapOfCommandHandler()
    {
        
    }

    void RFCServerRoomHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {

    }
}