//
// Created by zozo on 18/01/18.
//

#include "RFCHandler.hpp"

void RTypeServer::RFCHandler::initMapOfCommandHandler()
{
    _CommandHandler.insert({RTypeServer::ERR, &RFCError});
    _CommandHandler.insert({RTypeServer::LOGIN, &RFCOk});
    _CommandHandler.insert({RTypeServer::OK, &RFCLogin});
    _CommandHandler.insert({RTypeServer::STATUS, &RFCStatus});
    _CommandHandler.insert({RTypeServer::NEWENTITY, &RFCNewEntity});
    _CommandHandler.insert({RTypeServer::MOVENTITY, &RFCMovEntity});
    _CommandHandler.insert({RTypeServer::DELENTITY, &RFCDelEntity});
}

void RTypeServer::RFCHandler::RFCError()
{

}

void RTypeServer::RFCHandler::RFCLogin()
{

}

void RTypeServer::RFCHandler::RFCOk()
{

}

void RTypeServer::RFCHandler::RFCStatus()
{

}

void RTypeServer::RFCHandler::RFCNewEntity()
{

}

void RTypeServer::RFCHandler::RFCMovEntity()
{

}

void RTypeServer::RFCHandler::RFCDelEntity()
{

}