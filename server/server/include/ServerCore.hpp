//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_SERVERCORE_HPP
#define R_TYPE_SERVERCORE_HPP

#ifdef _WIN32
#define _WIN32_WINNT 0x0501
#endif

#include "IServerUdpSocket.hpp"
#include "ServerUdp.hpp"
#include "MessageQueue.hpp"
#include "RFCHandler.hpp"
#include "RoomPool.hpp"

#define NUMBER_OF_ROOM 4

namespace RTypeServer
{
    class ServerCore
    {
    public:
        ServerCore(unsigned short port);

        ~ServerCore() = default;

        ServerCore(const ServerCore &) = delete;

        ServerCore &operator=(const ServerCore &) = delete;

        void start();

    private:
        MessageQueue<RTypeProtocol::Message> _messageQueue;
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> _lobbyServer;
        RoomPool _rooms;
    };
}

#endif //R_TYPE_SERVERCORE_HPP
