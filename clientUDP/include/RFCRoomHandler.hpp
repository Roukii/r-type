//
// Created by zozo on 21/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include "Protocol/Message.hpp"
#include "Protocol/IServerUdpSocket.hpp"
#include "Protocol/IRFCHandler.hpp"

namespace RTypeClient
{
    class RFCRoomHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCRoomHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCRoomHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket);
        ~RFCRoomHandler() override = default;
        RFCRoomHandler(const RFCRoomHandler &) = delete;
        RFCRoomHandler &operator=(const RFCRoomHandler &) = delete;

    public :
        void executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID) override;

    private:
        void initMapOfCommandHandler();

    private:
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };

}


#endif //R_TYPE_RFCCLIENTHANDLER_HPP
