//
// Created by zozo on 23/01/18.
//

#include "RFCClientHandler.hpp"

namespace RTypeClient
{
    RFCClientHandler::RFCClientHandler(std::shared_ptr<IClientUdpSocket> &socket, CoreInfo &info)
            : _socket(socket), _info(info)
    {
        initMapOfCommandHandler();
    }

    void RFCClientHandler::initMapOfCommandHandler()
    {
        _CommandHandler.insert({RTypeProtocol::INFO_ROOM, &RFCClientHandler::RFCInfoRoom});
    }

    void RFCClientHandler::RFCInfoRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        CoreInfo::RoomInfo newRoom;

        newRoom.port = getPortFromChar(currentMessage);
        newRoom.playerNbr = currentMessage._msg.get()->data._room._nb_player;
        newRoom.inGame = false;
        _info.addElemToRoom(newRoom);

        std::cout << "room nb player : " << (int) currentMessage._msg.get()->data._room._nb_player << std::endl;
        std::cout << "room p ready : " << (int) currentMessage._msg.get()->data._room._player_ready[0] << std::endl;
        std::cout << "room port : " << getPortFromChar(currentMessage) << std::endl;
        std::cout << "room port pour enzo le fdp : " <<  (int) currentMessage._msg.get()->data._room._port[0]<< std::endl;
        std::cout << "room port 2 pour enzo le fdp : " <<  (int) currentMessage._msg.get()->data._room._port[1] << std::endl;
    }

    void RFCClientHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        std::cout << "message command : " << msg._msg.get()->_header._code << std::endl;
        auto codeCommand = static_cast<RTypeProtocol::code>(msg._msg->_header._code);
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

    unsigned short RFCClientHandler::getPortFromChar(RTypeProtocol::Message &currentMessage)
    {
        union
        {
            char ch[2];
            unsigned short n;
        } char2short;

        char2short.ch[0] = currentMessage._msg.get()->data._room._port[0];
        char2short.ch[1] = currentMessage._msg.get()->data._room._port[1];

        return char2short.n;
    }

}