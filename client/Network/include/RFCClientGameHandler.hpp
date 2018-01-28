//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCCLIENTGAMEHANDLER_HPP
#define R_TYPE_RFCCLIENTGAMEHANDLER_HPP

#include <map>
#include "Entity.hpp"
#include "AGameEngine.hpp"
#include "IRFCHandler.hpp"
#include "IClientUdpSocket.hpp"

namespace RTypeClient {
    class RFCClientGameHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCClientGameHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;
        std::map<int, std::shared_ptr<UgandaEngine::Entity>> &_entity;
        std::shared_ptr<UgandaEngine::AGameEngine> &_engine;

    public:
        RFCClientGameHandler(std::shared_ptr<IClientUdpSocket> &socket, std::map<int, std::shared_ptr<UgandaEngine::Entity>> &ent, std::shared_ptr<UgandaEngine::AGameEngine> &eng);
        ~RFCClientGameHandler() override = default;
        RFCClientGameHandler(const RFCClientGameHandler &) = delete;
        RFCClientGameHandler &operator=(const RFCClientGameHandler &) = delete;

        void executeCommand(RTypeProtocol::Message &msg, size_t ownerID) override;

    private:
        void initMapOfCommandHandler();

        void RFCMoveEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCDelEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCNewEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);

        void getPosFromMessage(RTypeProtocol::Message &, std::shared_ptr<UgandaEngine::Entity> &ent);
        int getIdFromChar(RTypeProtocol::Message &);
    private:
        std::shared_ptr<IClientUdpSocket> &_socket;
        mapOfCommand _CommandHandler;


    };
}

#endif //R_TYPE_RFCCLIENTGAMEHANDLER_HPP
