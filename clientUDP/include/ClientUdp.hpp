//
// Created by Alexandre on 1/11/2018.
//

#ifndef R_TYPE_CLIENTUDP_HPP
#define R_TYPE_CLIENTUDP_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include "Random.h"

#define MAX_SIZE_MSG 2048

class ClientUdp
{
public:
    ClientUdp(const std::string &,
              unsigned int,
              unsigned int);

    ~ClientUdp();

    ClientUdp(const ClientUdp &) = delete;

    ClientUdp &operator=(const ClientUdp &) = delete;

    bool isRunning() { return _isRunning;}
    void run();
    void send(const std::string &message);
private:
    void startReceive();
    bool checkPort();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
    boost::asio::ip::udp::endpoint _serverEndpoint;
    char *_data;
    std::thread _serviceThread;
    bool _isRunning;
};


#endif //R_TYPE_CLIENTUDP_HPP
