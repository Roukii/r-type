//
// Created by zozo on 23/01/18.
//

#include "RFCGameHandler.hpp"

namespace RTypeServer {
    RFCGameHandler::RFCGameHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket) : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCGameHandler::initMapOfCommandHandler()
    {
        _CommandHandler.insert({RTypeProtocol::NEW_ENTITY, &RFCGameHandler::RFCNewEntity});
        _CommandHandler.insert({RTypeProtocol::MOV_ENTITY, &RFCGameHandler::RFCMovEntity});
        _CommandHandler.insert({RTypeProtocol::DEL_ENTITY, &RFCGameHandler::RFCDelEntity});
    }

    void RFCGameHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end()) {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }

    void RFCGameHandler::RFCNewEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        //TODO: recup les donnes du AENTITY et les envoyer pareil pour les fonctions en dessous
    }

    void RFCGameHandler::RFCMovEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCmoveantitai lol" << std::endl;
    }

    void RFCGameHandler::RFCDelEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCdelentitaie lol" << std::endl;
    }
}