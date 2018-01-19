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
        _lobbyServer.get()->runServer();
    }
}