//
// Created by Alexandre on 1/10/2018.
//

#include "../include/ServerUdp.hpp"

namespace RTypeServer
{
    ServerUdp::ServerUdp(boost::asio::io_service &io_service)
        : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), PORT_SERVER))
    {
        startReceive();
    }

    ServerUdp::~ServerUdp()
    {}

    void ServerUdp::startReceive()
    {
//        _socket.async_receive(boost)
    }

}