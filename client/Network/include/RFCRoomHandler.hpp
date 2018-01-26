//
// Created by zozo on 21/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include "Message.hpp"
#include "IServerUdpSocket.hpp"
#include "IRFCHandler.hpp"
#include "IClientUdpSocket.hpp"

namespace RTypeClient
{
    class RFCRoomHandler : public RTypeProtocol::IRFCHandler
    {
        typedef void (RFCRoomHandler::*function)(RTypeProtocol::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeProtocol::code, function>;

    public:
        RFCRoomHandler(IClientUdpSocket &socket);
        ~RFCRoomHandler() override = default;
        RFCRoomHandler(const RFCRoomHandler &) = delete;
        RFCRoomHandler &operator=(const RFCRoomHandler &) = delete;

    public :
        void executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID) override;

    private:
        void initMapOfCommandHandler();

    private:
        IClientUdpSocket &_socket;
        mapOfCommand _CommandHandler;
    };

}


#endif //R_TYPE_RFCCLIENTHANDLER_HPP
