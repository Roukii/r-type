//
// Created by Alexandre on 1/10/2018.
//

#include "ServerCore.hpp"
#include "RTypeException.hpp"

int main(int ac, char **av)
{
    RTypeServer::ServerCore core;

    try {
        core.start();
    }
    catch (RTypeException &e){
        std::cout << e.what() << std::endl;
    }


    return 0;
}