//
// Created by Alexandre on 18/01/2018.
//

#include "ServerCore.hpp"
#include "RTypeException.hpp"

namespace RTypeServer
{
    ServerCore::ServerCore(unsigned short port)
    : _lobbyServer(std::make_shared<ServerUdp>(_messageQueue, port)),
      _rooms(NUMBER_OF_ROOM)
    {
        std::cout << "Server port : " << port << std::endl;
        if (_lobbyServer.get() == nullptr)
            throw RTypeException("Error : can't start socket");
    }

    void ServerCore::start()
    {

        _lobbyServer.get()->runServerWithThread();
        _rooms.startRooms();

        RFCHandler rfcHandler(_lobbyServer, _rooms);

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