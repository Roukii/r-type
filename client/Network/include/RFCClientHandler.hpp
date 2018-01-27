//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include <iostream>
#include "IRFCHandler.hpp"
#include "IClientUdpSocket.hpp"

namespace RTypeClient
{
    class RFCClientHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCClientHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCClientHandler(IClientUdpSocket &socket);
        ~RFCClientHandler() override = default;
        RFCClientHandler(const RFCClientHandler &) = delete;
        RFCClientHandler &operator=(const RFCClientHandler &) = delete;

        void executeCommand(RTypeProtocol::Message &msg, size_t ownerID) override;

    private:
        void initMapOfCommandHandler();
        void RFCInfoRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);

        unsigned short getPortFromChar(RTypeProtocol::Message &currentMessage);

    private:
        IClientUdpSocket &_socket;
        mapOfCommand _CommandHandler;


    };
}

#endif //R_TYPE_RFCCLIENTHANDLER_HPP