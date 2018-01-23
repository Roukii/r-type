//
// Created by Alexandre on 1/10/2018.
//

#ifndef R_TYPE_SERVERUDP_HPP
#define R_TYPE_SERVERUDP_HPP

#define MAX_SIZE_MSG 2048

#include <boost/asio.hpp>
#include <functional>
#include <memory>
#include <vector>
#include <string>
#include <thread>
#include "IServerUdpSocket.hpp"
#include "MessageQueue.hpp"
#include "Message.hpp"
#include "RFCHandler.hpp"

using endpoint = boost::asio::ip::udp::endpoint;

namespace RTypeServer
{
    class ServerUdp : public IServerUdpSocket
    {
    public:
        ServerUdp(MessageQueue<Message> &, unsigned short port);

        ~ServerUdp() override;

        ServerUdp(const ServerUdp &) = delete;

        ServerUdp &operator=(const ServerUdp &) = delete;

        void SendToClient(const Message &, std::size_t) override;
        void SendToAll(const Message &) override;
        void SendToAllExcept(const Message &, std::size_t) override;

        void runServer() override;
        void runServerWithThread() override;
        bool isRunning() const override;
        std::thread &getThread() override;
        static bool checkPort(unsigned short port);
        unsigned short getPort() const override;

        void shutdown() override;

    private:
        void send(const Message &, endpoint);
        void startReceive();
        void handleError(const boost::system::error_code &, endpoint);
        void removeDisconnectedClient(endpoint);
        bool endpointExist(endpoint) const;
        std::size_t clientIDFromEndpoint(endpoint) const;

    private:
        boost::asio::io_service io_service;
        boost::asio::ip::udp::socket    _socket;
        MessageQueue<Message> &_messageQueue;
        std::thread _serviceThread;
        std::vector<endpoint> _clientsList;
        endpoint _lastEndpoint;
        Message _msg;
        bool _running;
        unsigned short _port;
    };
}

#endif //R_TYPE_SERVERUDP_HPP
