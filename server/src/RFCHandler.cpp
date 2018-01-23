//
// Created by zozo on 18/01/18.
//

#include "RFCHandler.hpp"

namespace RTypeServer
{

    RFCHandler::RFCHandler(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket)
            : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCHandler::initMapOfCommandHandler()
    {
        _CommandHandler[RTypeProtocol::ERR] = &RFCHandler::RFCError;
        _CommandHandler.insert({RTypeProtocol::ERR, &RFCHandler::RFCError});
        _CommandHandler.insert({RTypeProtocol::OK, &RFCHandler::RFCLogin});
        _CommandHandler.insert({RTypeProtocol::STATUS, &RFCHandler::RFCStatus});
        _CommandHandler.insert({RTypeProtocol::NEW_ENTITY, &RFCHandler::RFCNewEntity});
        _CommandHandler.insert({RTypeProtocol::MOV_ENTITY, &RFCHandler::RFCMovEntity});
        _CommandHandler.insert({RTypeProtocol::DEL_ENTITY, &RFCHandler::RFCDelEntity});
    }

    void RFCHandler::RFCError(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCERROR wala c gg wp" << std::endl;
    }

    void RFCHandler::RFCLogin(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCLogin lagin" << std::endl;
    }

    void RFCHandler::RFCStatus(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::RFCNewEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCentitaie lol" << std::endl;
    }

    void RFCHandler::RFCMovEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCmoveantitai lol" << std::endl;

    }

    void RFCHandler::RFCDelEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCdelentitaie lol" << std::endl;

    }

    void RFCHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }
}