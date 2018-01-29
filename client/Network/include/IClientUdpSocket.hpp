//
// Created by Alexandre on 23/01/2018.
//

#ifndef R_TYPE_ICLIENTUDPSOCKET_HPP
#define R_TYPE_ICLIENTUDPSOCKET_HPP

#include <thread>
#include "Message.hpp"

#define WRONG_OWNER_ID 666

class IClientUdpSocket
{
public:
    virtual ~IClientUdpSocket() = default;

    virtual void run() = 0;
    virtual void runWithThread() = 0;
    virtual bool isRunning() const = 0;
    virtual void SendToServer(RTypeProtocol::Message &) = 0;
    virtual std::thread &getThread() = 0;

    virtual void shutdown() = 0;
};


#endif //R_TYPE_ICLIENTUDPSOCKET_HPP
