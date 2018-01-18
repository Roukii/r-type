//
// Created by Alexandre on 16/01/2018.
//

#include "ClientUdp.hpp"
#include <cstdlib>
#include <iostream>

int main(int ac,char **av)
{
    if (ac != 3)
    {
        std::cout << "Usage : ./client host port" << std::endl;
        return 0;
    }

    ClientUdp client(av[1], atoi(av[2]), 4343);

    while (client.isRunning())
    {
        std::string shell;
        std::getline(std::cin, shell);
        client.send(shell);
    }
    return 0;
}