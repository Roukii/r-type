//
// Created by Alexandre on 19/01/2018.
//

#ifndef R_TYPE_ISERVERUDPSOCKET_HPP
#define R_TYPE_ISERVERUDPSOCKET_HPP

#include <string>
#include <thread>

namespace RTypeServer
{
    class IServerUdpSocket
    {
    public:
        virtual ~IServerUdpSocket()
        {};

        virtual void runServer() = 0;
        virtual void runServerWithThread() = 0;
        virtual bool isRunning() const = 0;
        virtual std::thread &getThread() = 0;

        virtual void SendToClient(const std::string &, std::size_t) = 0;
        virtual void SendToAll(const std::string &) = 0;
        virtual void SendToAllExcept(const std::string &, std::size_t) = 0;
    };
}

#endif //R_TYPE_ISERVERUDPSOCKET_HPP
