//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include "../../server/include/IRFCHandler.hpp"
#include "../../server/include/IServerUdpSocket.hpp"

namespace RTypeClient
{
    class RFCClientHandler : public IRFCHandler
    {
        typedef void (RFCClientHandler::*function)(RTypeServer::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeServer::code, function>;

    public:
        RFCClientHandler(std::shared_ptr<RTypeServer::IServerUdpSocket> &socket);
        ~RFCClientHandler() = default;
        RFCClientHandler(const RFCClientHandler &) = delete;
        RFCClientHandler &operator=(const RFCClientHandler &) = delete;

    private:
        std::shared_ptr<RTypeServer::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;

        void initMapOfCommandHandler();

        void executeCommand(RTypeServer::Message &msg, size_t ownerID);
    };
}

#endif //R_TYPE_RFCCLIENTHANDLER_HPP
