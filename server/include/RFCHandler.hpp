//
// Created by zozo on 18/01/18.
//

#ifndef R_TYPE_RFCHANDLER_HPP
#define R_TYPE_RFCHANDLER_HPP

#include <iostream>
#include <map>

#include "IServerUdpSocket.hpp"
#include "IRFCHandler.hpp"
#include "RoomPool.hpp"

namespace RTypeServer
{
    class RFCHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket, RoomPool &roomPool);
        ~RFCHandler() = default;
        RFCHandler(const RFCHandler &) = delete;
        RFCHandler &operator=(const RFCHandler &) = delete;

    public:
        void executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID) override;

    private:
        void initMapOfCommandHandler();
        void RFCError(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCStatus(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCOk(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCConnect(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCEndOfGame(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCRooms(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCAction(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);

        void getPortFromShortToChar(RTypeProtocol::Message &currentMessage, std::shared_ptr<RTypeServer::Room> &room);

    private:
        RoomPool _roomPool;
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };

}

#endif //R_TYPE_RFCHANDLER_HPP
