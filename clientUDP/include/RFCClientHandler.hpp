//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include "Protocol/IRFCHandler.hpp"
#include "Protocol/IServerUdpSocket.hpp"

namespace RTypeClient
{
    class RFCClientHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCClientHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCClientHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket);
        ~RFCClientHandler() = default;
        RFCClientHandler(const RFCClientHandler &) = delete;
        RFCClientHandler &operator=(const RFCClientHandler &) = delete;

    private:
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;

        void initMapOfCommandHandler();

        void executeCommand(RTypeProtocol::Message &msg, size_t ownerID);
    };
}

#endif //R_TYPE_RFCCLIENTHANDLER_HPP
