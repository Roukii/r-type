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
        _CommandHandler.insert({RTypeProtocol::ERR, &RFCHandler::RFCError});
        _CommandHandler.insert({RTypeProtocol::STATUS, &RFCHandler::RFCStatus});
        _CommandHandler.insert({RTypeProtocol::OK, &RFCHandler::RFCOk});
        _CommandHandler.insert({RTypeProtocol::CONNECT, &RFCHandler::RFCConnect});
        _CommandHandler.insert({RTypeProtocol::START_GAME, &RFCHandler::RFCStartGame});
        _CommandHandler.insert({RTypeProtocol::END_OF_GAME, &RFCHandler::RFCEndOfGame});
    }

    void RFCHandler::RFCError(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCERROR wala c gg wp" << std::endl;
    }


    void RFCHandler::RFCStatus(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::RFCOk(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::RFCConnect(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::RFCStartGame(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
    }

    void RFCHandler::RFCEndOfGame(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID)
    {
        std::cout << "RFCStatus lol" << std::endl;
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