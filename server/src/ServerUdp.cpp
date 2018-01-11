//
// Created by Alexandre on 1/10/2018.
//

#include <iostream>
#include "ServerUdp.hpp"

namespace RTypeServer
{
    ServerUdp::ServerUdp(boost::asio::io_service &io_service)
        : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), PORT_SERVER))
    {
        std::cout << _socket.local_endpoint().address().to_string() << std::endl;
        std::cout << "start receive" << std::endl;
        startReceive();
    }

    ServerUdp::~ServerUdp()
    {}

    void ServerUdp::startReceive()
    {
        _socket.async_receive_from(
                boost::asio::buffer(test, MAX_SIZE_MSG), _remoteEndpoint,
                [this](const boost::system::error_code& error, // Result of operation.
                       std::size_t bytes_transferred)
                {
                    if (!error || error == boost::asio::error::message_size)
                    {
                        boost::shared_ptr<std::string> message(
                                new std::string("Wilkomen WARLD !"));

                        test = std::string("test wilkomen").c_str();
                        _socket.async_send_to(boost::asio::buffer(*message), _remoteEndpoint,
                                              boost::bind(&ServerUdp::handleSend, this, message,
                                                          boost::asio::placeholders::error,
                                                          boost::asio::placeholders::bytes_transferred));
                    }
                    startReceive();

                });

    }

    void ServerUdp::handleReceive(const boost::system::error_code& error,
                       std::size_t /*bytes_transferred*/)
    {
        if (!error || error == boost::asio::error::message_size)
        {
            boost::shared_ptr<std::string> message(
                    new std::string("Wilkomen WARLD !"));

            _socket.async_send_to(boost::asio::buffer(*message), _remoteEndpoint,
                                  boost::bind(&ServerUdp::handleSend, this, message,
                                              boost::asio::placeholders::error,
                                              boost::asio::placeholders::bytes_transferred));
        }
        startReceive();
    }

    void ServerUdp::handleSend(boost::shared_ptr<std::string> /*message*/,
                     const boost::system::error_code& /*error*/,
                     std::size_t /*bytes_transferred*/)
    {
        std::cout << "send succesfull" << std::endl;
    }
}
