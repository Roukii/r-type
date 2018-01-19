//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_CLIENTMANAGER_HPP
#define R_TYPE_CLIENTMANAGER_HPP

#include <vector>
#include "OnSocketEvent.h"

namespace RTypeServer
{
    class ClientManager : public OnSocketEvent
    {
    public:
        ClientManager();

        ~ClientManager();

        ClientManager(const ClientManager &) = delete;

        ClientManager &operator=(const ClientManager &) = delete;

    public:
        void onNewClient(IClientSocket *socket) override;
        void onReadFromSocket(IClientSocket &socket) override;
        void onWriteFromSocket(IClientSocket &socket) override;
        void onDisconnect(IClientSocket &socket) override;
        void onCloseServer() override;

    private:
        std::vector<std::shared_ptr<IClientSocket> > _Clients;
    };
}

#endif //R_TYPE_CLIENTMANAGER_HPP
