//
// Created by Alexandre on 1/10/2018.
//

#include "ServerCore.hpp"
#include "RTypeException.hpp"

int main(int ac, char **av)
{

    try {
        if (RTypeServer::ServerUdp::checkPort(PORT_MAIN_SERVER))
        {
            throw RTypeException("Error : port taken");
        }

        RTypeServer::ServerCore core;

        core.start();
    }
    catch (RTypeException &e){
        std::cout << e.what() << std::endl;
    }


    return 0;
}