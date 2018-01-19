//
// Created by Alexandre on 19/01/2018.
//

#ifndef R_TYPE_ISERVERUDPSOCKET_HPP
#define R_TYPE_ISERVERUDPSOCKET_HPP

namespace RTypeServer
{
    class IServerUdpSocket
    {
    public:
        virtual ~IServerUdpSocket()
        {};

        virtual void runServer() = 0;
    };
}

#endif //R_TYPE_ISERVERUDPSOCKET_HPP
