//
// Created by zozo on 21/01/18.
//

#ifndef R_TYPE_RFCCLIENTHANDLER_HPP
#define R_TYPE_RFCCLIENTHANDLER_HPP

#include <map>
#include "../../server/include/Message.hpp"
#include "../../server/include/IServerUdpSocket.hpp"

namespace RTypeClient
{
    class RFCClientHandler
    {
        typedef void (RFCClientHandler::*function)(RTypeServer::Message &, std::size_t);
        using mapOfCommand = std::map<RTypeServer::code, function>;

    public:
        RFCClientHandler(std::shared_ptr<RTypeServer::IServerUdpSocket> &socket);
        ~RFCClientHandler() = default;
        RFCClientHandler(const RFCClientHandler &) = delete;
        RFCClientHandler &operator=(const RFCClientHandler &) = delete;


        void executeCommand(RTypeServer::Message &currentMessage, std::size_t _currentOwnerID);
        void initMapOfCommandHandler();

    private:
        std::shared_ptr<RTypeServer::IServerUdpSocket> &_socket;
        mapOfCommand _CommandHandler;
    };

}


#endif //R_TYPE_RFCCLIENTHANDLER_HPP
