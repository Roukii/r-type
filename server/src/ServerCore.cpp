//
// Created by Alexandre on 18/01/2018.
//

#include "ServerCore.hpp"

namespace RTypeServer
{
    ServerCore::ServerCore()
    : _lobbyServer(std::make_shared<ServerUdp>(_messageQueue, PORT_MAIN_SERVER)),
      _rooms(NUMBER_OF_ROOM)
    {
    }

    void ServerCore::start()
    {
        RFCHandler rfcHandler(_lobbyServer);

        _lobbyServer.get()->runServerWithThread();
        _rooms.startRooms();
        while(_lobbyServer.get()->isRunning())
        {
            if (!_messageQueue.isEmpty())
            {
                rfcHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
                _messageQueue.pop();
            }
            _rooms.updateRooms();
        }
        _lobbyServer.get()->shutdown();
        _rooms.shutdownRooms();
    }
}