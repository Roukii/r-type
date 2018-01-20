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

namespace RTypeServer
{
    class RFCHandler
    {
        typedef void (RFCHandler::*function)(Message &, std::size_t);
        using mapOfCommand = std::map<code, function>;

    public:
        RFCHandler(std::shared_ptr<IServerUdpSocket> &socket);
        ~RFCHandler() = default;
        RFCHandler(const RFCHandler &) = delete;
        RFCHandler &operator=(const RFCHandler &) = delete;


        void executeCommand(Message &currentMessage, std::size_t _currentOwnerID);

        void RFCError(Message &currentMessage, std::size_t _currentOwnerID);
        void RFCOk(Message &currentMessage, std::size_t _currentOwnerID);
        void RFCLogin(Message &currentMessage, std::size_t _currentOwnerID);
        void RFCStatus(Message &currentMessage, std::size_t _currentOwnerID);
        void RFCNewEntity(Message &currentMessage, std::size_t _currentOwnerID);
        void RFCMovEntity(Message &currentMessage, std::size_t _currentOwnerID);
        void RFCDelEntity(Message &currentMessage, std::size_t _currentOwnerID);

        void initMapOfCommandHandler();

    private:
        std::shared_ptr<IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };

}

#endif //R_TYPE_RFCHANDLER_HPP
