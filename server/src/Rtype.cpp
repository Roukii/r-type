//
// Created by Alexandre on 1/10/2018.
//

#include "ServerCore.hpp"
#include "RTypeException.hpp"

int main(int ac, char **av)
{

    try {
        RTypeServer::ServerCore core(RTypeServer::ServerUdp::createAPort());

        core.start();
    }
    catch (RTypeException &e){
        std::cout << e.what() << std::endl;
    }


    return 0;
}