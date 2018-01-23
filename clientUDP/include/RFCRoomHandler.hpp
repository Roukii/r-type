//
// Created by zozo on 21/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include "../../server/include/Message.hpp"
#include "../../server/include/IServerUdpSocket.hpp"
#include "../../server/include/IRFCHandler.hpp"

namespace RTypeClient
{
    class RFCRoomHandler : public IRFCHandler
    {
        typedef void (RFCRoomHandler::*function)(RTypeServer::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeServer::code, function>;

    public:
        RFCRoomHandler(std::shared_ptr<RTypeServer::IServerUdpSocket> &socket);
        ~RFCRoomHandler() = default;
        RFCRoomHandler(const RFCRoomHandler &) = delete;
        RFCRoomHandler &operator=(const RFCRoomHandler &) = delete;

    private:
        std::shared_ptr<RTypeServer::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };

}


#endif //R_TYPE_RFCCLIENTHANDLER_HPP
