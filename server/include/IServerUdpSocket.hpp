//
// Created by Alexandre on 19/01/2018.
//

#ifndef R_TYPE_ISERVERUDPSOCKET_HPP
#define R_TYPE_ISERVERUDPSOCKET_HPP

#include <string>
#include <thread>
#include "Message.hpp"

namespace RTypeServer
{
    class IServerUdpSocket
    {
    public:
        virtual ~IServerUdpSocket() = default;

        virtual void runServer() = 0;
        virtual void runServerWithThread() = 0;
        virtual bool isRunning() const = 0;
        virtual std::thread &getThread() = 0;
        virtual unsigned short getPort() const = 0;

        virtual void shutdown() = 0;

        virtual void SendToClient(const Message &, std::size_t) = 0;
        virtual void SendToAll(const Message &) = 0;
        virtual void SendToAllExcept(const Message &, std::size_t) = 0;
    };
}

#endif //R_TYPE_ISERVERUDPSOCKET_HPP
