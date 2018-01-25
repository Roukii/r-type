//
// Created by Alexandre on 16/01/2018.
//

#include <memory>
#include <cstdlib>
#include <iostream>
#include "Message.hpp"
#include "Random.h"
#include "ClientUdp.hpp"
#include "RFCClientHandler.hpp"
#include "MessageQueue.hpp"

int main(int ac,char **av)
{
    if (ac != 3)
    {
        std::cout << "Usage : ./client host port" << std::endl;
        return 0;
    }

    Random<unsigned short> random;
    unsigned short port = random.Generate(4000, 5000);
    while (ClientUdp<RTypeProtocol::Message>::checkPort(port))
    {
        port = random.Generate(4000, 5000);
    }

    std::cout << "port = " << port << std::endl;

    RTypeClient::MessageQueue<RTypeProtocol::Message> messageQueue;
    ClientUdp<RTypeProtocol::Message> client(av[1], atoi(av[2]), port, messageQueue);
    RTypeClient::RFCClientHandler rfcHandler(client);

    client.runWithThread();
    std::string shell;
    while (client.isRunning() || shell == "exit")
    {
        if (!messageQueue.isEmpty())
        {
            std::cout << "a message arrived" << std::endl;
            rfcHandler.executeCommand(messageQueue.peekMessage(), messageQueue.peekOwnerID());
            messageQueue.pop();
        }
        std::getline(std::cin, shell);
        if (shell == "room")
        {
            RTypeProtocol::Message _msg;
            _msg._msg.get()->_header._code = RTypeProtocol::ROOMS;
            client.SendToServer(_msg);

        }
        if (shell == "test")
        {
            RTypeProtocol::Message _msg;
            _msg._msg.get()->_header._code = RTypeProtocol::OK;
            _msg._msg.get()->data._status._id[0] = 'a';
            _msg._msg.get()->data._status._id[1] = 'b';
            _msg._msg.get()->data._status._id[2] = 'c';
            _msg._msg.get()->data._status._id[3] = 'd';
            client.SendToServer(_msg);
        }
        if (shell == "test2")
        {
            RTypeProtocol::Message _msg;
            _msg._msg.get()->_header._code = RTypeProtocol::NEW_ENTITY;
            client.SendToServer(_msg);
        }
        if (shell == "error")
        {
            RTypeProtocol::Message _msg;
            _msg._msg.get()->_header._code = RTypeProtocol::ERR;
            client.SendToServer(_msg);
        }
    }
    std::cout << "end thread" << std::endl;
    client.shutdown();
    return 0;
}