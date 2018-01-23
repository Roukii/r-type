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
        _CommandHandler.insert({RTypeProtocol::PLAYER_JOIN_ROOM, &RFCServerRoomHandler::RFCPlayerJoinRoom});
        _CommandHandler.insert({RTypeProtocol::READY_ROOM, &RFCServerRoomHandler::RFCReadyRoom});
        _CommandHandler.insert({RTypeProtocol::START_GAME, &RFCServerRoomHandler::RFCStartGame});
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
    }

    void RFCServerRoomHandler::RFCReadyRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
    }

    void RFCServerRoomHandler::RFCStartGame(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
    }
}