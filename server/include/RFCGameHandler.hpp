//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCGAMEHANDLER_HPP
#define R_TYPE_RFCGAMEHANDLER_HPP

#include <map>

#include "Message.hpp"
#include "IRFCHandler.hpp"
#include "IServerUdpSocket.hpp"
#include "../../utils/GameEngine/include/Entity.hpp"

namespace RTypeServer {
    class RFCGameHandler : public RTypeProtocol::IRFCHandler {
        typedef void (RFCGameHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCGameHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket, std::vector<UgandaEngine::entity::Entity> &_entities);
        ~RFCGameHandler() = default;
        RFCGameHandler(const RFCGameHandler &) = delete;
        RFCGameHandler &operator=(const RFCGameHandler &) = delete;

        void executeCommand(RTypeProtocol::Message &msg, size_t ownerID) override;

        void RFCNewEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCMovEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCDelEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);


    private:

        void initMapOfCommandHandler();


        std::vector<UgandaEngine::entity::Entity> _entities;
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };
}

#endif //R_TYPE_RFCGAMEHANDLER_HPP
