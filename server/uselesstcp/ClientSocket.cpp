//
// Created by Alexandre on 18/01/2018.
//

#include "ClientSocket.hpp"

namespace RTypeServer
{
    ClientSocket::ClientSocket(boost::asio::io_service &io_service)
    : _socket(io_service)
    {
        _data = new char[2048];
    }

    ClientSocket::~ClientSocket()
    {
        delete _data;
    }

    const std::string &ClientSocket::getIp() const
    {
        return _socket.remote_endpoint().address().to_string();
    }

    void ClientSocket::writeHandler()
    {
    // TODO make it work baby
    }

    void ClientSocket::readHandler(std::function<void(IClientSocket &client, std::size_t byte)> callback)
    {
        boost::asio::async_read(_socket, boost::asio::buffer(_data, 2048),
                                boost::asio::transfer_at_least(3),
                                [this, callback](const boost::system::error_code& ec, std::size_t bytesTransfered)
                                {
                                    if (!ec)
                                    {
                                        std::cout << "byte transfered" << bytesTransfered << std::endl;
                                        std::cout << "end read\n-----------------------" << std::endl;
                                        readHandler(callback);
                                        callback(*this, bytesTransfered);
                                    }
                                    else
                                    {
                                        std::cout << ec.message() << std::endl;
                                    }
                                });
    }
}