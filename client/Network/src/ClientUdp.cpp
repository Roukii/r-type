//
// Created by zozo on 26/01/18.
//

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
    _socket.send_to(boost::asio::buffer(message._msg.get(), sizeof(message._msg.get())), _serverEndpoint);
}

void ClientUdp::startReceive()
{
    _socket.async_receive_from(boost::asio::buffer(_msg._msg.get(), sizeof(_msg._msg.get())),
                               _remoteEndpoint,
                               [this](const boost::system::error_code &ec,
                                      std::size_t bytes)
                               {
                                   if (!ec)
                                   {
                                       _messageQueue.addMessage(_msg, 0);
                                       std::cout << "receive a message" << std::endl;
                                       std::cout << "msg code : " << (int) _msg._msg.get()->_header._code << std::endl;
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

bool ClientUdp::checkPort(unsigned short port)
{
    boost::asio::io_service service;
    boost::asio::ip::tcp::acceptor a(service);

    boost::system::error_code ec;
    a.open(boost::asio::ip::tcp::v4(), ec) || a.bind({boost::asio::ip::tcp::v4(), port }, ec);

    return ec == boost::asio::error::address_in_use;
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
