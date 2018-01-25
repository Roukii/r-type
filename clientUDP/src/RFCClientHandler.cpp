//
// Created by zozo on 23/01/18.
//

#include "RFCClientHandler.hpp"

namespace RTypeClient
{
    RFCClientHandler::RFCClientHandler(IClientUdpSocket<RTypeProtocol::Message> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCClientHandler::initMapOfCommandHandler()
    {

    }

    void RFCInfoRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "room nb player : " << (int) currentMessage._msg.get()->data._room._nb_player << std::endl;
        std::cout << "room p ready : " << (int) currentMessage._msg.get()->data._room._player_ready[0] << std::endl;
        std::cout << "room port : " << currentMessage._msg.get()->data._room._port << std::endl;
    }

    void RFCClientHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

}