//
// Created by Alexandre on 16/01/2018.
//

#include "ClientUdp.hpp"
#include <cstdlib>
#include <iostream>
#include "Random.h"

int main(int ac,char **av)
{
    if (ac != 3)
    {
        std::cout << "Usage : ./client host port" << std::endl;
        return 0;
    }

    Random random;
    unsigned short port = random.GenerateRandomNumber(4000, 5000);
    while (ClientUdp::checkPort(port))
    {
        port = random.GenerateRandomNumber(4000, 5000);
    }

    std::cout << "port = " << port << std::endl;

    ClientUdp client(av[1], atoi(av[2]), port);

    std::cout << "shell " << std::endl;

    while (client.isRunning())
    {
        std::string shell;
        std::getline(std::cin, shell);
        client.send(shell);
    }
    std::cout << "end thread" << std::endl;
    client.getThread().join();
    return 0;
}