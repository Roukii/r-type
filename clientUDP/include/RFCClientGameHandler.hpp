//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTGAMEHANDLER_HPP
#define R_TYPE_RFCCLIENTGAMEHANDLER_HPP

#include <map>
#include "IRFCHandler.hpp"
#include "IClientUdpSocket.hpp"

namespace RTypeClient {
    class RFCClientGameHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCClientGameHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCClientGameHandler(IClientUdpSocket<RTypeProtocol::Message> &socket);
        ~RFCClientGameHandler() = default;
        RFCClientGameHandler(const RFCClientGameHandler &) = delete;
        RFCClientGameHandler &operator=(const RFCClientGameHandler &) = delete;

        void executeCommand(RTypeProtocol::Message &msg, size_t ownerID) override;

    private:
        IClientUdpSocket<RTypeProtocol::Message> &_socket;
        mapOfCommand _CommandHandler;

        void initMapOfCommandHandler();

    };
}

#endif //R_TYPE_RFCCLIENTGAMEHANDLER_HPP
