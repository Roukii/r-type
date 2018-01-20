//
// Created by Alexandre on 1/10/2018.
//

#ifndef R_TYPE_SERVERUDP_HPP
#define R_TYPE_SERVERUDP_HPP

#define PORT_SERVER 4242
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
        ServerUdp(MessageQueue<Message> &);

        ~ServerUdp();

        ServerUdp(const ServerUdp &) = delete;

        ServerUdp &operator=(const ServerUdp &) = delete;

        void SendToClient(const std::string &, std::size_t) override;
        void SendToAll(const std::string &) override;
        void SendToAllExcept(const std::string &, std::size_t) override;

        void runServer() override;
        void runServerWithThread() override;
        bool isRunning() const override;
        std::thread &getThread() override;

    private:
        void send(const std::string &, endpoint);
        void startReceive();
        void handleError(const boost::system::error_code &, endpoint);
        void removeDisconnectedClient(endpoint);
        void cleanBuffer();
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
        char *_data;
        bool _running;
    };
}

#endif //R_TYPE_SERVERUDP_HPP
