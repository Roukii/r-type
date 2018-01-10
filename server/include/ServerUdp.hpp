//
// Created by Alexandre on 1/10/2018.
//

#ifndef R_TYPE_SERVERUDP_HPP
#define R_TYPE_SERVERUDP_HPP

#define PORT_SERVER 4242

#include <boost/asio.hpp>

namespace RTypeServer
{
    class ServerUdp
    {
    public:
        ServerUdp(boost::asio::io_service &);

        ~ServerUdp();

        ServerUdp(const ServerUdp &) = delete;

        ServerUdp &operator=(const ServerUdp &) = delete;

    private:
        void startReceive();
    private:
        //boost::asio::io_service         &_service;
        boost::asio::ip::udp::socket    _socket;
    };
}

#endif //R_TYPE_SERVERUDP_HPP
