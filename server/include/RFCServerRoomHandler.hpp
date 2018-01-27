//
// Created by zozo on 23/01/18.
//

#ifndef R_TYPE_RFCSERVERROOMHANDLER_HPP
#define R_TYPE_RFCSERVERROOMHANDLER_HPP

#include <map>
#include "IRFCHandler.hpp"
#include "IServerUdpSocket.hpp"
#include "RoomInfo.hpp"

namespace RTypeServer {
    class RFCServerRoomHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCServerRoomHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCServerRoomHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &);
        ~RFCServerRoomHandler() override = default;
        RFCServerRoomHandler(const RFCServerRoomHandler &) = delete;
        RFCServerRoomHandler &operator=(const RFCServerRoomHandler &) = delete;

    public :
        void executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID) override;

        void RFCPlayerJoinRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCReadyRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCPlayerLeaveRoom(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCPlayerReady(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);
        void RFCPlayerNotReady(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID);

        RoomInfo getRoomInfo() const {return _roomInfo; }

    private:
        void initMapOfCommandHandler();

    private:
        mapOfCommand _CommandHandler;
        RoomInfo _roomInfo;
    };
}

#endif //R_TYPE_RFCSERVERROOMHANDLER_HPP
