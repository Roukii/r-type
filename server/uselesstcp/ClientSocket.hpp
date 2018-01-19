//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_CLIENTSOCKET_HPP
#define R_TYPE_CLIENTSOCKET_HPP

#include "IClientSocket.h"
#include <boost/asio.hpp>
#include <iostream>

namespace RTypeServer
{
    class ClientSocket : public IClientSocket
    {
    public:
        ClientSocket(boost::asio::io_service &io_service);

        ~ClientSocket();

        ClientSocket(const ClientSocket &) = delete;

        ClientSocket &operator=(const ClientSocket &) = delete;

    public:
        const std::string &getIp() const override;
        //virtual Message &getRequest() = 0;
        //virtual ClientData &getData() = 0;
        void readHandler(std::function<void(IClientSocket &client, std::size_t byte)> callback) override;
        void writeHandler() override;

        boost::asio::ip::tcp::socket &getSocket() { return _socket; }

    private:
        boost::asio::ip::tcp::socket _socket;
        //TODO change to message struct for binary protocol
        char *_data;
    };
}

#endif //R_TYPE_CLIENTSOCKET_HPP
