//
// Created by zozo on 23/01/18.
//

#include "RFCClientHandler.hpp"

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
        if (currentMessage._msg->data._room._playing == true)
        {
            std::cout << "in game" << std::endl;
            newRoom.playerNbr = 4;
            newRoom.inGame = true;
        }
        else
            newRoom.inGame = false;
        _info.addElemToRoom(newRoom);

        std::cout << "room nb player : " << (int) currentMessage._msg.get()->data._room._nb_player << std::endl;
        std::cout << "room port : " << getPortFromChar(currentMessage) << std::endl;
    }

    void RFCClientHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        auto codeCommand = static_cast<RTypeProtocol::code>(msg._msg->_header._code);
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
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
