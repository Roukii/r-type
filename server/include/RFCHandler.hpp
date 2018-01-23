//
// Created by zozo on 18/01/18.
//

#ifndef R_TYPE_RFCHANDLER_HPP
#define R_TYPE_RFCHANDLER_HPP

#include <iostream>
#include <map>

#include "IServerUdpSocket.hpp"
#include "Message.hpp"
#include "RFCProtocol.hpp"
#include "IRFCHandler.hpp"

namespace RTypeServer
{
    class RFCHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket);
        ~RFCHandler() = default;
        RFCHandler(const RFCHandler &) = delete;
        RFCHandler &operator=(const RFCHandler &) = delete;

        void RFCError(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCOk(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCLogin(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCStatus(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCNewEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCMovEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCDelEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);

    public:
        void executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID) override;

    private:
        void initMapOfCommandHandler();

    private:
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };

}

#endif //R_TYPE_RFCHANDLER_HPP
