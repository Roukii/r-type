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
        _CommandHandler.insert({RTypeProtocol::OK, &RFCHandler::RFCOk});
        _CommandHandler.insert({RTypeProtocol::ROOMS, &RFCHandler::RFCRooms});
    }

    void RFCHandler::RFCRooms(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        currentMessage._msg.get()->_header._code = RTypeProtocol::INFO_ROOM;
        for (auto &i : _roomPool._rooms)
        {
            getPortFromShortToChar(currentMessage, i);
            currentMessage._msg.get()->data._room._nb_player = i.get()->getPlayer();
            if (i->getState() == RoomState::PLAYING_STATE)
            {
                std::cout << "Room is playing" << std::endl;
                currentMessage._msg.get()->data._room._nb_player = 4;
                currentMessage._msg.get()->data._room._playing = true;
            }
            else
                currentMessage._msg.get()->data._room._playing = false;
            for (int nb = 0; nb < 4; nb++)
                currentMessage._msg.get()->data._room._player_ready[nb] = i.get()->getReady(nb);
            _socket.get()->SendToClient(currentMessage, _currentOwnerID);
        }
    }

    void RFCHandler::RFCError(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
    }

    void RFCHandler::RFCOk(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        _socket->SendToClient(currentMessage, _currentOwnerID);
    }

    void RFCHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        std::cout << "rfc handler main : " << (RTypeProtocol::code)msg._msg->_header._code << std::endl;
        auto codeCommand = static_cast<RTypeProtocol::code>(msg._msg->_header._code);
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
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
    }
}