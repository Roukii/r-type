//
// Created by Alexandre on 1/10/2018.
//

#include <iostream>
#include "ServerUdp.hpp"

namespace RTypeServer
{
    ServerUdp::ServerUdp(MessageQueue<std::string> &queue)
        : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), PORT_SERVER)),
          _messageQueue(queue)
    {
        _data = new char[MAX_SIZE_MSG];
        cleanBuffer();

        std::cout << _socket.local_endpoint().address().to_string() << std::endl;
    }

    ServerUdp::~ServerUdp()
    {
        delete _data;
    }

    void ServerUdp::SendToClient(const std::string &message, std::size_t clientId)
    {
        if (clientId < _clientsList.size())
           send(message, _clientsList[clientId]);
    }

    void ServerUdp::SendToAll(const std::string &message)
    {
        for (auto i = 0; i < _clientsList.size(); i++)
            send(message, _clientsList[i]);
    }

    void ServerUdp::SendToAllExcept(const std::string &message, std::size_t clientId)
    {
        for (auto i = 0; i < _clientsList.size(); i++)
            if (i != clientId)
                send(message, _clientsList[i]);
    }

    void ServerUdp::startReceive()
    {
        _socket.async_receive_from(
                boost::asio::buffer(_data, MAX_SIZE_MSG), _lastEndpoint,
                [this](const boost::system::error_code& error,
                       std::size_t bytes_transferred)
                {
                    std::cout << "nb client = " << _clientsList.size() << std::endl;
                    if (!error || error == boost::asio::error::message_size)
                    {
                        _clientsList.push_back(_lastEndpoint);

                        std::cout << "remote endpoint = " << _lastEndpoint.address() << std::endl;
                        std::cout << "port endpoint = " << _lastEndpoint.port() << std::endl;

                        std::cout << std::string(_data) << std::endl;
                        _messageQueue.addMessage(std::string(_data), _clientsList.size() - 1);
                        cleanBuffer();
                        SendToClient("Wilkomen WARLD !", _clientsList.size() - 1);
                    }
                    else
                    {
                        std::cout << error.message() << std::endl;
                        handleError(error, _lastEndpoint);
                    }
                    startReceive();
                });

    }

    void ServerUdp::send(const std::string &message, endpoint target)
    {
        _socket.send_to(boost::asio::buffer(message), target);
    }

    void ServerUdp::handleError(const boost::system::error_code & error, endpoint target)
    {
        if ((boost::asio::error::eof == error) ||
            (boost::asio::error::connection_reset == error))
        {
            removeDisconnectedClient(_lastEndpoint);
        }
    }

    void ServerUdp::removeDisconnectedClient(endpoint target)
    {
        for (unsigned int i = 0; i < _clientsList.size(); i++)
        {
            if (_clientsList[i] == target)
                _clientsList.erase(_clientsList.begin() + i);
        }
    }

    void ServerUdp::cleanBuffer()
    {
        for (unsigned int i = 0; i < MAX_SIZE_MSG; i++)
            _data[i] = 0;
    }

    void ServerUdp::runServer()
    {
        startReceive();
    }
}
