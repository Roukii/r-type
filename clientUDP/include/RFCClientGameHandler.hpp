//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTGAMEHANDLER_HPP
#define R_TYPE_RFCCLIENTGAMEHANDLER_HPP

#include <map>
#include "../../server/include/IRFCHandler.hpp"
#include "../../server/include/IServerUdpSocket.hpp"

namespace RTypeClient {
    class RFCClientGameHandler : public IRFCHandler
    {
        typedef void (RFCClientGameHandler::*function)(RTypeServer::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeServer::code, function>;

    public:
        RFCClientGameHandler(std::shared_ptr<RTypeServer::IServerUdpSocket> &socket);
        ~RFCClientGameHandler() = default;
        RFCClientGameHandler(const RFCClientGameHandler &) = delete;
        RFCClientGameHandler &operator=(const RFCClientGameHandler &) = delete;

    private:
        std::shared_ptr<RTypeServer::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;

        void initMapOfCommandHandler();

        void executeCommand(RTypeServer::Message &msg, size_t ownerID);
    };
}

#endif //R_TYPE_RFCCLIENTGAMEHANDLER_HPP
