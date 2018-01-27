//
// Created by zozo on 23/01/18.
//

#include "RFCServerRoomHandler.hpp"

namespace RTypeServer
{
    RFCServerRoomHandler::RFCServerRoomHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket) : _roomInfo(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCServerRoomHandler::initMapOfCommandHandler()
    {
        _CommandHandler.insert({RTypeProtocol::PLAYER_JOIN_ROOM, &RFCServerRoomHandler::RFCPlayerJoinRoom});
        _CommandHandler.insert({RTypeProtocol::READY_ROOM, &RFCServerRoomHandler::RFCReadyRoom});
        _CommandHandler.insert({RTypeProtocol::PLAYER_LEAVE_ROOM, &RFCServerRoomHandler::RFCPlayerLeaveRoom});
        _CommandHandler.insert({RTypeProtocol::PLAYER_READY, &RFCServerRoomHandler::RFCPlayerReady});
        _CommandHandler.insert({RTypeProtocol::PLAYER_NOT_READY, &RFCServerRoomHandler::RFCPlayerNotReady});
    }

    void RFCServerRoomHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

    void RFCServerRoomHandler::RFCPlayerJoinRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        _roomInfo.addPlayer(_currentOwnerID);
    }

    void RFCServerRoomHandler::RFCPlayerLeaveRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        _roomInfo.delPlayer(_currentOwnerID);
    }

    void RFCServerRoomHandler::RFCPlayerReady(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        _roomInfo.playerReady(_currentOwnerID);
    }

    void RFCServerRoomHandler::RFCPlayerNotReady(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        _roomInfo.playerUnReady(_currentOwnerID);
    }

    void RFCServerRoomHandler::RFCReadyRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        for (auto i : _roomInfo.getPlayers())
        {
            if (!i)
            {
                // TODO: si tout le monde n'est pas pret faire un truc enfin je pense
            }
        }

        // TODO: lancer la game ici
    }
}