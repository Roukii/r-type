//
// Created by zozo on 18/01/18.
//

#include "RFCHandler.hpp"

namespace RTypeServer
{

    RFCHandler::RFCHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket, RoomPool &rooms)
            : _socket(socket), _roomPool(rooms)
    {
        initMapOfCommandHandler();
    }

    void RFCHandler::initMapOfCommandHandler()
    {
        _CommandHandler.insert({RTypeProtocol::ERR, &RFCHandler::RFCError});
        _CommandHandler.insert({RTypeProtocol::STATUS, &RFCHandler::RFCStatus});
        _CommandHandler.insert({RTypeProtocol::OK, &RFCHandler::RFCOk});
        _CommandHandler.insert({RTypeProtocol::CONNECT, &RFCHandler::RFCConnect});
        _CommandHandler.insert({RTypeProtocol::END_OF_GAME, &RFCHandler::RFCEndOfGame});
        _CommandHandler.insert({RTypeProtocol::ROOMS, &RFCHandler::RFCRooms});
//        _CommandHandler.insert({RTypeProtocol::INFO_ROOM, &RFCHandler::RFCInfoRoom});

    }

//    void RFCHandler::RFCRooms(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
//    {
//        std::string tmp = std::to_string(_roomPool._numberOfRoom);
//        for (int i = 0; i < 4; i++)
//            currentMessage._msg.get()->data._nb_room._room[i] = tmp[i];
//        _socket.get()->SendToClient(currentMessage, _currentOwnerID);
//    }

    void RFCHandler::RFCRooms(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        for (auto i : _roomPool._rooms)
        {
            std::string tmp = std::to_string(i.get()->getPort());
            for (int nb = 0; nb < 2; nb++)
                currentMessage._msg.get()->data._room._port[nb] = tmp[nb];
            currentMessage._msg.get()->data._room._nb_player = i.get()->getPlayer();

            for (int nb = 0; nb < 4; nb++)
                currentMessage._msg.get()->data._room._player_ready[nb] = i.get()->getReady(nb);
            _socket.get()->SendToClient(currentMessage, _currentOwnerID);
        }
    }


    void RFCHandler::RFCError(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCERROR wala c gg wp" << std::endl;
    }


    void RFCHandler::RFCStatus(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::RFCOk(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCOK lol" << std::endl;
    }

    void RFCHandler::RFCConnect(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::RFCEndOfGame(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }
}