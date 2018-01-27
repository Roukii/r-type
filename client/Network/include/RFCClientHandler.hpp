//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include <iostream>
#include "CoreInfo.hpp"
#include "IRFCHandler.hpp"
#include "IClientUdpSocket.hpp"

namespace RTypeClient
{
    class RFCClientHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCClientHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCClientHandler(std::shared_ptr<IClientUdpSocket> &socket, CoreInfo &info);
        ~RFCClientHandler() override = default;
        RFCClientHandler(const RFCClientHandler &) = delete;
        RFCClientHandler &operator=(const RFCClientHandler &) = delete;

        void executeCommand(RTypeProtocol::Message &msg, size_t ownerID) override;

    private:
        void initMapOfCommandHandler();
        void RFCInfoRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);

        unsigned short getPortFromChar(RTypeProtocol::Message &currentMessage);

    private:
        std::shared_ptr<IClientUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
        CoreInfo &_info;

    };
}

#endif //R_TYPE_RFCCLIENTHANDLER_HPP
