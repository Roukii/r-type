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
        _CommandHandler.insert({RTypeProtocol::ROOMS, &RFCServerRoomHandler::RFCRooms});
        _CommandHandler.insert({RTypeProtocol::JOIN_ROOM, &RFCServerRoomHandler::RFCJoinRoom});
        _CommandHandler.insert({RTypeProtocol::INFO_ROOM, &RFCServerRoomHandler::RFCInfoRoom});
        _CommandHandler.insert({RTypeProtocol::PLAYER_JOIN_ROOM, &RFCServerRoomHandler::RFCPlayerJoinRoom});
        _CommandHandler.insert({RTypeProtocol::READY_ROOM, &RFCServerRoomHandler::RFCReadyRoom});
    }

    void RFCServerRoomHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {

    }

    void RFCServerRoomHandler::RFCRooms(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID){

    }

    void RFCServerRoomHandler::RFCInfoRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCServerRoomHandler::RFCJoinRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCServerRoomHandler::RFCPlayerJoinRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCServerRoomHandler::RFCReadyRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

}