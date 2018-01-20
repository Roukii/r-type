//
// Created by zozo on 18/01/18.
//

#include "RFCHandler.hpp"

namespace RTypeServer
{

    RFCHandler::RFCHandler(std::shared_ptr<IServerUdpSocket> &socket)
            : _socket(socket)
    {
        initMapOfCommandHandler();
    }

    void RFCHandler::initMapOfCommandHandler()
    {
        _CommandHandler[ERR] = &RFCHandler::RFCError;
        _CommandHandler.insert({ERR, &RFCHandler::RFCError});
        _CommandHandler.insert({LOGIN, &RFCHandler::RFCOk});
        _CommandHandler.insert({OK, &RFCHandler::RFCLogin});
        _CommandHandler.insert({STATUS, &RFCHandler::RFCStatus});
        _CommandHandler.insert({NEWENTITY, &RFCHandler::RFCNewEntity});
        _CommandHandler.insert({MOVENTITY, &RFCHandler::RFCMovEntity});
        _CommandHandler.insert({DELENTITY, &RFCHandler::RFCDelEntity});
    }

    void RFCHandler::RFCError(Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCHandler::RFCLogin(Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCHandler::RFCOk(Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCHandler::RFCStatus(Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCHandler::RFCNewEntity(Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCHandler::RFCMovEntity(Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCHandler::RFCDelEntity(Message &currentMessage, std::size_t _currentOwnerID)
    {

    }

    void RFCHandler::executeCommand(Message &msg, std::size_t ownerID)
    {
        code codeCommand = (code) msg._msg->_header._code;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
            //_CommandHandler[codeCommand](msg, ownerID);
        }
    }
}