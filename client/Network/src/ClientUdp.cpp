//
// Created by zozo on 26/01/18.
//

#include "RTypeException.hpp"
#include "ClientUdp.hpp"


ClientUdp::ClientUdp(const std::string &host,
                     unsigned short serverPort,
                     unsigned short localPort,
                     RTypeClient::MessageQueue<RTypeProtocol::Message> &messageQueue)
        : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), localPort)),
          _isRunning(false), _host(host), _serverPort(serverPort), _localPort(localPort), _messageQueue(messageQueue)
{
    boost::asio::ip::udp::resolver resolver(io_service);
    boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), _host, std::to_string(_serverPort));
    _serverEndpoint = *resolver.resolve(query);
    startReceive();
}

ClientUdp::~ClientUdp()
{
    _socket.close();
}

void ClientUdp::run()
{
    while (!io_service.stopped())
    {
        try
        {
            _isRunning = true;
            io_service.run();
        }
        catch (const std::exception &e)
        {
            std::cout << "Client: network exception: " << e.what() << std::endl;
            _isRunning = false;
        }
        catch (...)
        {
            std::cout << "Unknown exception in client network thread" << std::endl;
            _isRunning = false;
        }
    }
}

void ClientUdp::SendToServer(RTypeProtocol::Message &message)
{
    _socket.send_to(boost::asio::buffer(message._msg.get(), message.getSizeMsg()), _serverEndpoint);
}

void ClientUdp::startReceive()
{
    _socket.async_receive_from(boost::asio::buffer(_msg._msg.get(), _msg.getSizeMsg()),
                               _remoteEndpoint,
                               [this](const boost::system::error_code &ec,
                                      std::size_t bytes)
                               {
                                   std::cout << "[DBG] Receive message with code : " << (int) this->_msg._msg->_header._code << std::endl;
                                   if (!ec)
                                   {
                                       _messageQueue.addMessage(_msg, 0);
                                   }
                                   else
                                   {
                                       std::cout << "error : " << ec.message() << std::endl;
                                       if (boost::asio::error::bad_descriptor)
                                       {
                                           std::cout << "bad file descriptor wala" << std::endl;
                                           _isRunning = false;
                                       }
                                   }
                                   startReceive();
                               });
}

unsigned short ClientUdp::createAPort()
{
    boost::asio::io_service service;
    boost::asio::ip::tcp::acceptor acceptor(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 0));
    return acceptor.local_endpoint().port();
}

void ClientUdp::runWithThread()
{
    _serviceThread = std::thread(&ClientUdp::run, this);
}

void ClientUdp::shutdown()
{
    io_service.stop();
    if (_serviceThread.joinable())
        _serviceThread.join();
}

