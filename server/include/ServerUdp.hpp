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
#include "IServerUdpSocket.hpp"
#include "MessageQueue.hpp"

using endpoint = boost::asio::ip::udp::endpoint;

namespace RTypeServer
{
    class ServerUdp : public IServerUdpSocket
    {
    public:
        ServerUdp(MessageQueue<std::string> &);

        ~ServerUdp();

        ServerUdp(const ServerUdp &) = delete;

        ServerUdp &operator=(const ServerUdp &) = delete;

        void SendToClient(const std::string &, std::size_t);
        void SendToAll(const std::string &);
        void SendToAllExcept(const std::string &, std::size_t);

        void runServer() override;

    private:
        void send(const std::string &, endpoint);
        void startReceive();
        void handleError(const boost::system::error_code &, endpoint);
        void removeDisconnectedClient(endpoint);
        void cleanBuffer();

    private:
        boost::asio::io_service io_service;
        boost::asio::ip::udp::socket    _socket;
        MessageQueue<std::string> &_messageQueue;
        std::vector<endpoint> _clientsList;
        endpoint _lastEndpoint;
        char *_data;
    };
}

#endif //R_TYPE_SERVERUDP_HPP
