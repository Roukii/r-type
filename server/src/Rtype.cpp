//
// Created by Alexandre on 1/10/2018.
//

#include "ServerCore.hpp"

int main(int ac, char **av)
{
    RTypeServer::ServerCore core;

    core.start();
    /*
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
*/

    return 0;
}