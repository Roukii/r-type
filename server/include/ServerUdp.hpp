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
        void handleReceive(const boost::system::error_code& error, std::size_t);
        void handleSend(boost::shared_ptr<std::string>, const boost::system::error_code&, std::size_t);
    private:
        //boost::asio::io_service         &_service;
        boost::asio::ip::udp::socket    _socket;
        boost::asio::ip::udp::endpoint _remoteEndpoint;
        boost::array<char, 1> recv_buffer_;
        char test[MAX_SIZE_MSG];
        //std::vector<char> _message;
    };
}

#endif //R_TYPE_SERVERUDP_HPP
