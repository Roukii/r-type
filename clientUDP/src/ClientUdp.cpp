//
// Created by Alexandre on 1/11/2018.
//

#include "ClientUdp.hpp"


ClientUdp::ClientUdp(const std::string &host,
                     unsigned short serverPort,
                     unsigned short localPort)
    : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), localPort)),
      _serviceThread(&ClientUdp::run, this),
      _isRunning(true), _host(host), _serverPort(serverPort), _localPort(localPort)
{
    std::cout << "size of msg : " << sizeof(_msg._msg.get()) << std::endl;
    _msg._msg.get()->_header._code = RTypeProtocol::code::ERR;
    _msg._msg.get()->_header._owner = 1;
}

ClientUdp::~ClientUdp()
{
    _socket.close();
}

void ClientUdp::run()
{
    boost::asio::ip::udp::resolver resolver(io_service);
    boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), _host, std::to_string(_serverPort));
    _serverEndpoint = *resolver.resolve(query);

    startReceive();
    while (!io_service.stopped())
    {
        try
        {
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

void ClientUdp::send(const std::string &message)
{
    _socket.send_to(boost::asio::buffer(_msg._msg.get(), sizeof(_msg._msg.get())), _serverEndpoint);
    _msg._msg.get()->_header._code++;
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
                                      std::cout << "receive a message" << std::endl;
                                      std::cout << "msg code : " << (int) _msg._msg.get()->_header._code << std::endl;
                                  }
                                  else
                                  {
                                      std::cout << "error : " << ec.message() << std::endl;
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