//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTGAMEHANDLER_HPP
#define R_TYPE_RFCCLIENTGAMEHANDLER_HPP

#include <map>
#include "../../utils/Protocol/IRFCHandler.hpp"
#include "../../utils/Protocol/IServerUdpSocket.hpp"

namespace RTypeClient {
    class RFCClientGameHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCClientGameHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCClientGameHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket);
        ~RFCClientGameHandler() = default;
        RFCClientGameHandler(const RFCClientGameHandler &) = delete;
        RFCClientGameHandler &operator=(const RFCClientGameHandler &) = delete;

        void executeCommand(RTypeProtocol::Message &msg, size_t ownerID) override;

    private:
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;

        void initMapOfCommandHandler();

    };
}

#endif //R_TYPE_RFCCLIENTGAMEHANDLER_HPP
