//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCGAMEHANDLER_HPP
#define R_TYPE_RFCGAMEHANDLER_HPP

#include <map>
#include "Message.hpp"
#include "IRFCHandler.hpp"
#include "IServerUdpSocket.hpp"

namespace RTypeServer {
    class RFCGameHandler : public IRFCHandler {
        typedef void (RFCGameHandler::*function)(Message &, std::size_t);
        using mapOfCommand = std::map<code, function>;

    public:
        RFCGameHandler(std::shared_ptr<IServerUdpSocket> &socket);
        ~RFCHandler() = default;
        RFCGameHandler(const RFCGameHandler &) = delete;
        RFCGameHandler &operator=(const RFCGameHandler &) = delete;

    private:

        void initMapOfCommandHandler();

        void executeCommand(Message &msg, size_t ownerID);


        std::shared_ptr<IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };
}

#endif //R_TYPE_RFCGAMEHANDLER_HPP
