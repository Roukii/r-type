//
// Created by Alexandre on 1/10/2018.
//

#ifndef R_TYPE_SERVERUDP_HPP
#define R_TYPE_SERVERUDP_HPP

#define PORT_SERVER 4242
#define MAX_SIZE_MSG 2048

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <functional>
#include <memory>
#include <vector>
#include <string>

using endpoint = boost::asio::ip::udp::endpoint;

namespace RTypeServer
{
    class ServerUdp
    {
    public:
        ServerUdp(boost::asio::io_service &);

        ~ServerUdp();

        ServerUdp(const ServerUdp &) = delete;

        ServerUdp &operator=(const ServerUdp &) = delete;

        void SendToClient(const std::string &, unsigned int);
        void SendToAll(const std::string &);
        void SendToAllExcept(const std::string &, unsigned int);

    private:
        void startReceive();
        void send(const std::string &, endpoint);
        void handleError(const boost::system::error_code &, endpoint);
        void removeDisconnectedClient(endpoint);

    private:
        boost::asio::ip::udp::socket    _socket;
        std::vector<endpoint> _clientsList;
        endpoint _lastEndpoint;
        char *_data;
    };
}

#endif //R_TYPE_SERVERUDP_HPP
