//
// Created by Alexandre on 28/09/2017.
//

#include "Network.h"

namespace RTypeServer
{
    Network::Network()
    {
        _running = true;
        if (_running == true)
            initServer();
    }

    /*
    Network::~Network()
    {
        _Server->closeServer();
        _SocketManager->onCloseServer();
    }
*/
    void Network::addNewClient(IClientSocket *newClient)
    {
        _SocketManager->onNewClient(newClient);
    }

    void Network::initServer()
    {
        _Server = std::shared_ptr<IServerSocket>(new ServerTcp());
        _SocketManager = std::shared_ptr<OnSocketEvent>(new ClientManager());
        _Server->startServer(PORT_TCP,
            [=](IClientSocket *newClient)
            {
                addNewClient(newClient);
            });
    }

    const bool Network::isRunning() const
    {
        return _running;
    }
}
