//
// Created by Alexandre on 1/10/2018.
//

#include <iostream>

#include "ServerUdp.hpp"

namespace RTypeServer
{
    ServerUdp::ServerUdp(MessageQueue<RTypeProtocol::Message> &queue, unsigned short port)
        : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
          _messageQueue(queue),
          _running(false),
          _port(port)
    {}

    ServerUdp::~ServerUdp() = default;

    void ServerUdp::SendToClient(const RTypeProtocol::Message &message, std::size_t clientId)
    {
        if (clientId < _clientsList.size())
           send(message, _clientsList[clientId]);
    }

    void ServerUdp::SendToAll(const RTypeProtocol::Message &message)
    {
        for (auto i = 0; i < _clientsList.size(); i++)
            send(message, _clientsList[i]);
    }

    void ServerUdp::SendToAllExcept(const RTypeProtocol::Message &message, std::size_t clientId)
    {
        for (auto i = 0; i < _clientsList.size(); i++)
            if (i != clientId)
                send(message, _clientsList[i]);
    }

    void ServerUdp::startReceive()
    {
        _socket.async_receive_from(
                boost::asio::buffer(_msg._msg.get(), sizeof(_msg._msg.get())), _lastEndpoint,
                [this](const boost::system::error_code& error,
                       std::size_t bytes_transferred)
                {
                    if (!error || error == boost::asio::error::message_size)
                    {
                        if (!endpointExist(_lastEndpoint))
                        {
                            _clientsList.push_back(_lastEndpoint);
                            SendToClient(_msg, _clientsList.size() - 1);
                            _msg._msg.get()->_header._code++;
                        }
                        _messageQueue.addMessage(_msg, clientIDFromEndpoint(_lastEndpoint));
                        SendToAllExcept(_msg, _clientsList.size() - 1);
                    }
                    else
                    {
                        std::cout << "error : " << std::endl;
                        std::cout << error.message() << std::endl;
                        handleError(error, _lastEndpoint);
                    }
                    startReceive();
                });

    }

    void ServerUdp::send(const RTypeProtocol::Message &message, endpoint target)
    {
        _socket.send_to(boost::asio::buffer(message._msg.get(), sizeof(message._msg.get())), target);
    }

    void ServerUdp::handleError(const boost::system::error_code & error, endpoint target)
    {
        if ((boost::asio::error::eof == error) ||
            (boost::asio::error::connection_reset == error))
        {
            std::cout << "client disconnected" << std::endl;
            removeDisconnectedClient(_lastEndpoint);
        }
        else
        {
            _running = false;
        }
    }

    void ServerUdp::removeDisconnectedClient(endpoint target)
    {
        for (auto i = 0; i < _clientsList.size(); i++)
        {
            if (_clientsList[i] == target)
                _clientsList.erase(_clientsList.begin() + i);
        }
    }

    void ServerUdp::runServer()
    {
        _running = true;
        startReceive();
        io_service.run();
    }

    bool ServerUdp::endpointExist(endpoint target) const
    {
        for (auto i = 0; i < _clientsList.size(); i++)
        {
            if (_clientsList[i] == target)
                return true;
        }
        std::cout << "new client" << std::endl;
        return false;
    }

    std::size_t ServerUdp::clientIDFromEndpoint(endpoint target) const
    {
        for(auto i = 0; i < _clientsList.size(); i++)
        {
            if (_clientsList[i] == target)
                return i;
        }
        return _clientsList.size();
    }

    bool ServerUdp::isRunning() const
    {
        return _running;
    }

    void ServerUdp::runServerWithThread()
    {
        _running = true;
        _serviceThread = std::thread(&ServerUdp::runServer, this);
    }

    std::thread &ServerUdp::getThread()
    {
        return _serviceThread;
    }

    void ServerUdp::shutdown()
    {
        if (!io_service.stopped())
            io_service.stop();
        _running = false;
        if (_serviceThread.joinable())
            _serviceThread.join();
    }

    bool ServerUdp::checkPort(unsigned short port)
    {
        boost::asio::io_service service;
        boost::asio::ip::tcp::acceptor a(service);

        boost::system::error_code ec;
        a.open(boost::asio::ip::tcp::v4(), ec) || a.bind({boost::asio::ip::tcp::v4(), port}, ec);

        return ec == boost::asio::error::address_in_use;
    }

    unsigned short ServerUdp::getPort() const
    {
        return _port;
    }
}
