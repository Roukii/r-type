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

using endpoint = boost::asio::ip::udp::endpoint;

namespace RTypeServer
{
    class ServerUdp : public RTypeProtocol::IServerUdpSocket
    {
    public:
        ServerUdp(MessageQueue<RTypeProtocol::Message> &, unsigned short port);

        ~ServerUdp() override;

        ServerUdp(const ServerUdp &) = delete;

        ServerUdp &operator=(const ServerUdp &) = delete;

        void SendToClient(const RTypeProtocol::Message &, std::size_t) override;
        void SendToAll(const RTypeProtocol::Message &) override;
        void SendToAllExcept(const RTypeProtocol::Message &, std::size_t) override;

        void removeClient(const std::size_t &) override;

        void runServer() override;
        void runServerWithThread() override;
        bool isRunning() const override;
        std::thread &getThread() override;
        static bool checkPort(unsigned short port);
        unsigned short getPort() const override;

        void shutdown() override;

    public:

        char getClients() const
        {
            std::vector<endpoint> vec = _clientsList;
            char k = 0;
            for (auto i : vec)
            {
                k++;
            }
            return k;
        }

        bool getReady(int nb) const
        {
            std::vector<bool> vec = _readylist;
            bool k;
            int t = 0;
            for (auto i : vec)
            {
                if (t == nb)
                {
                    k = i;
                    return (k);
                }
                t++;
            }
            return false;
        }


    private:
        void send(const RTypeProtocol::Message &, endpoint);
        void startReceive();
        void handleError(const boost::system::error_code &, endpoint);
        void removeDisconnectedClient(endpoint);
        bool endpointExist(endpoint) const;
        std::size_t clientIDFromEndpoint(endpoint) const;

    private:
        boost::asio::io_service io_service;
        boost::asio::ip::udp::socket    _socket;
        MessageQueue<RTypeProtocol::Message> &_messageQueue;
        std::thread _serviceThread;
        std::vector<endpoint> _clientsList;
        std::vector<bool> _readylist;
        endpoint _lastEndpoint;
        RTypeProtocol::Message _msg;
        bool _running;
        unsigned short _port;
    };
}

#endif //R_TYPE_SERVERUDP_HPP
