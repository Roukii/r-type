//
// Created by Alexandre on 1/11/2018.
//

#ifndef R_TYPE_CLIENTUDP_HPP
#define R_TYPE_CLIENTUDP_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include "RFCProtocol.hpp"
#include "Message.hpp"
#include "IClientUdpSocket.hpp"
#include "MessageQueue.hpp"

template<class T>
class ClientUdp : public IClientUdpSocket<T>
{
public:
    ClientUdp(const std::string &,
              unsigned short,
              unsigned short,
              RTypeClient::MessageQueue<RTypeProtocol::Message> &messageQueue);

    ~ClientUdp() override;

    ClientUdp(const ClientUdp &) = delete;

    ClientUdp &operator=(const ClientUdp &) = delete;

    void run() override;
    void runWithThread() override;

    bool isRunning() const override { return _isRunning;}
    void SendToServer(T &) override;
    static bool checkPort(unsigned short port);
    std::thread &getThread() override { return _serviceThread;}

    void shutdown() override;

private:
    void startReceive();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
    boost::asio::ip::udp::endpoint _serverEndpoint;
    T _msg;
    std::thread _serviceThread;
    bool _isRunning;
    const std::string &_host;
    unsigned short _serverPort;
    unsigned short _localPort;
    RTypeClient::MessageQueue<RTypeProtocol::Message> &_messageQueue;
};

template<class T>
ClientUdp<T>::ClientUdp(const std::string &host,
                        unsigned short serverPort,
                        unsigned short localPort,
                        RTypeClient::MessageQueue<RTypeProtocol::Message> &messageQueue)
        : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), localPort)),
          _isRunning(true), _host(host), _serverPort(serverPort), _localPort(localPort), _messageQueue(messageQueue)
{}

template<class T>
ClientUdp<T>::~ClientUdp()
{
    _socket.close();
}

template<class T>
void ClientUdp<T>::run()
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

template<class T>
void ClientUdp<T>::SendToServer(T &message)
{
    std::cout << "pass by template" << std::endl;
    _socket.send_to(boost::asio::buffer(message, sizeof(message)), _serverEndpoint);
}

template<>
void ClientUdp<RTypeProtocol::Message>::SendToServer(RTypeProtocol::Message &message)
{
    std::cout << "pass by protocol message" << std::endl;
    _socket.send_to(boost::asio::buffer(message._msg.get(), sizeof(message._msg.get())), _serverEndpoint);
}

template<class T>
void ClientUdp<T>::startReceive()
{
    _socket.async_receive_from(boost::asio::buffer(_msg, sizeof(_msg)),
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

template<>
void ClientUdp<RTypeProtocol::Message>::startReceive()
{
    std::cout << "pass by protocol message" << std::endl;
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
                                   }
                                   startReceive();
                               });
}

template<class T>
bool ClientUdp<T>::checkPort(unsigned short port)
{
    boost::asio::io_service service;
    boost::asio::ip::tcp::acceptor a(service);

    boost::system::error_code ec;
    a.open(boost::asio::ip::tcp::v4(), ec) || a.bind({boost::asio::ip::tcp::v4(), port }, ec);

    return ec == boost::asio::error::address_in_use;
}

template<class T>
void ClientUdp<T>::runWithThread()
{
    _isRunning = true;
    _serviceThread = std::thread(&ClientUdp::run, this);
}

template<class T>
void ClientUdp<T>::shutdown()
{
    io_service.stop();
    if (_serviceThread.joinable())
        _serviceThread.join();
}

#endif //R_TYPE_CLIENTUDP_HPP
