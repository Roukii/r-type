//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCSERVERROOMHANDLER_HPP
#define R_TYPE_RFCSERVERROOMHANDLER_HPP

#include <map>
#include "IRFCHandler.hpp"
#include "IServerUdpSocket.hpp"

namespace RTypeServer {
    class RFCServerRoomHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCServerRoomHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCServerRoomHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket);
        ~RFCServerRoomHandler() override = default;
        RFCServerRoomHandler(const RFCServerRoomHandler &) = delete;
        RFCServerRoomHandler &operator=(const RFCServerRoomHandler &) = delete;

    public :
        void executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID) override;

        void RFCRooms(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCJoinRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCInfoRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCPlayerJoinRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCReadyRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);

    private:
        void initMapOfCommandHandler();

    private:
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };
}

#endif //R_TYPE_RFCSERVERROOMHANDLER_HPP
