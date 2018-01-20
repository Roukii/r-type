//
// Created by Alexandre on 18/01/2018.
//

#include "ServerCore.hpp"

namespace RTypeServer
{
    ServerCore::ServerCore()
    : _lobbyServer(std::make_shared<ServerUdp>(_messageQueue))
    {
    }

    ServerCore::~ServerCore()
    {
    }

    void ServerCore::start()
    {
        RFCHandler rfcHandler(_lobbyServer);

        _lobbyServer.get()->runServerWithThread();
        while(_lobbyServer.get()->isRunning())
        {
            if (!_messageQueue.isEmpty())
            {
                std::cout << "is not empty" << std::endl;
                rfcHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
                _messageQueue.pop();
            }
        }
        _lobbyServer.get()->getThread().join();
    }
}