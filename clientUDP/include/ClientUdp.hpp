//
// Created by Alexandre on 1/11/2018.
//

#ifndef R_TYPE_CLIENTUDP_HPP
#define R_TYPE_CLIENTUDP_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>

#define MAX_SIZE_MSG 2048

class ClientUdp
{
public:
    ClientUdp(const std::string &,
              unsigned short,
              unsigned short);

    ~ClientUdp();

    ClientUdp(const ClientUdp &) = delete;

    ClientUdp &operator=(const ClientUdp &) = delete;

    bool isRunning() { return _isRunning;}
    void run();
    void send(const std::string &message);
    static bool checkPort(unsigned short port);


private:
    void startReceive();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
    boost::asio::ip::udp::endpoint _serverEndpoint;
    char *_data;
    std::thread _serviceThread;
    bool _isRunning;
    const std::string &_host;
    unsigned short _serverPort;
    unsigned short _localPort;
};


#endif //R_TYPE_CLIENTUDP_HPP
