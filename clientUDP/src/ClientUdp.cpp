//
// Created by Alexandre on 1/11/2018.
//

#include "ClientUdp.hpp"


ClientUdp::ClientUdp(const std::string &host,
                     unsigned int serverPort,
                     unsigned int localPort)
    : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), localPort)),
      _serviceThread(&ClientUdp::run, this),
      _isRunning(false)
{
    _data = new char[MAX_SIZE_MSG];
    for (unsigned int i = 0; i < MAX_SIZE_MSG; i++)
        _data[i] = 0;

    boost::asio::ip::udp::resolver resolver(io_service);
    boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), host, std::to_string(serverPort));
    _serverEndpoint = *resolver.resolve(query);

}

ClientUdp::~ClientUdp()
{
    delete _data;
}

void ClientUdp::run()
{

    std::cout << "debug lele run data shit" << std::endl;

    if (!_isRunning)
    {
        _isRunning = true;
        startReceive();
        while (!io_service.stopped())
        {
            try
            {
                io_service.run();
            }
            catch (const std::exception& e)
            {
                std::cout << "Client: network exception: " << e.what() << std::endl;
            }
            catch (...)
            {
                std::cout << "Unknown exception in client network thread" << std::endl;
            }
        }
    }
}

void ClientUdp::send(const std::string &message)
{
    _socket.send_to(boost::asio::buffer(message), _serverEndpoint);
}

void ClientUdp::startReceive()
{
    std::cout << "debug lele receu" << std::endl;
    _socket.async_receive_from(boost::asio::buffer(_data, MAX_SIZE_MSG),
                               _remoteEndpoint,
                              [this](const boost::system::error_code &ec,
                                     std::size_t bytes)
                              {
                                  std::cout << "debug lele inside" << std::endl;
                                  if (!ec)
                                  {
                                      std::string message(_data);
                                      std::cout << message << std::endl;
                                  }
                                  else
                                  {
                                      std::cout << "error : " << ec.message() << std::endl;
                                  }
                              });
}

bool ClientUdp::checkPort()
{
    boost::asio::ip::tcp::acceptor a(io_service);

    boost::system::error_code ec;
    a.open(boost::asio::ip::tcp::v4(), ec) || a.bind({boost::asio::ip::tcp::v4(), port }, ec);

    return ec == error::address_in_use;
}