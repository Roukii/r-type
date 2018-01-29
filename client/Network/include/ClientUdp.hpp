//
// Created by Alexandre on 1/11/2018.
//

#ifndef R_TYPE_CLIENTUDP_HPP
#define R_TYPE_CLIENTUDP_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include "RFCProtocol.hpp"
#include "Message.hpp"
#include "IClientUdpSocket.hpp"
#include "MessageQueue.hpp"

class ClientUdp : public IClientUdpSocket
{
public:
    ClientUdp(const std::string &,
              unsigned short,
              unsigned short,
              RTypeClient::MessageQueue<RTypeProtocol::Message> &messageQueue);

    ~ClientUdp() override;

    ClientUdp(const ClientUdp &) = delete;

    ClientUdp &operator=(const ClientUdp &) = delete;

    void run() override;
    void runWithThread() override;

    bool isRunning() const override { return _isRunning;}
    void SendToServer(RTypeProtocol::Message &) override;
    static unsigned short createAPort();
    std::thread &getThread() override { return _serviceThread;}

    void shutdown() override;

private:
    void startReceive();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
    boost::asio::ip::udp::endpoint _serverEndpoint;
    RTypeProtocol::Message _msg;
    std::thread _serviceThread;
    bool _isRunning;
    const std::string &_host;
    unsigned short _serverPort;
    unsigned short _localPort;
    RTypeClient::MessageQueue<RTypeProtocol::Message> &_messageQueue;
};

#endif //R_TYPE_CLIENTUDP_HPP
