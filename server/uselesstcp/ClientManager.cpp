//
// Created by Alexandre on 18/01/2018.
//

#include "ClientManager.hpp"

namespace RTypeServer
{
    ClientManager::ClientManager()
    {}

    ClientManager::~ClientManager()
    {}

    void RTypeServer::ClientManager::onReadFromSocket(IClientSocket &socket)
    {

    }

    void ClientManager::onNewClient(IClientSocket *socket)
    {

    }

    void ClientManager::onWriteFromSocket(IClientSocket &socket)
    {

    }

    void ClientManager::onDisconnect(IClientSocket &socket)
    {

    }

    void ClientManager::onCloseServer()
    {

    }
}