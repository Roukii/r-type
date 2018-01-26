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
        _CommandHandler.insert({RTypeProtocol::ACTION, &RFCHandler::RFCAction});
    }

    void RFCHandler::RFCRooms(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        currentMessage._msg.get()->_header._code = RTypeProtocol::INFO_ROOM;
        for (auto &i : _roomPool._rooms)
        {
            getPortFromShortToChar(currentMessage, i);
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

    void RFCHandler::RFCAction(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        
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

    void RFCHandler::getPortFromShortToChar(RTypeProtocol::Message &currentMessage, std::shared_ptr<RTypeServer::Room> &room)
    {
        union
        {
            char ch[2];
            unsigned short n;
        } char2short;

        char2short.n = room.get()->getPort();
        currentMessage._msg.get()->data._room._port[0] = char2short.ch[0];
        currentMessage._msg.get()->data._room._port[1] = char2short.ch[1];
        std::cout << "port 1 = " << (int) char2short.ch[0] << std::endl;
        std::cout << "port 2 = " << (int) char2short.ch[1] << std::endl;
    }
}