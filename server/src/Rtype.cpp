//
// Created by Alexandre on 1/10/2018.
//

#include "ServerUdp.hpp"

#include <iostream>
#include <boost/asio.hpp>

int main(int ac, char **av)
{
    try
    {
        boost::asio::io_service io_service;
        RTypeServer::ServerUdp server(io_service);
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "hello world !" << std::endl;
    return 0;
}