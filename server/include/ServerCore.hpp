//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_SERVERCORE_HPP
#define R_TYPE_SERVERCORE_HPP

#include "IServerUdpSocket.hpp"
#include "ServerUdp.hpp"
#include "MessageQueue.hpp"
#include "RFCHandler.hpp"

namespace RTypeServer
{
    class ServerCore
    {
    public:
        ServerCore();

        ~ServerCore();

        ServerCore(const ServerCore &) = delete;

        ServerCore &operator=(const ServerCore &) = delete;

        void start();

    private:
        MessageQueue<Message> _messageQueue;
        std::shared_ptr<IServerUdpSocket> _lobbyServer;
    };
}

#endif //R_TYPE_SERVERCORE_HPP
