//
// Created by zozo on 21/01/18.
//

#ifndef R_TYPE_IRFCHANDLER_HPP
#define R_TYPE_IRFCHANDLER_HPP

#include "Message.hpp"

class IRFCHandler
{
public:
    virtual ~IRFCHandler() = default;
    virtual void executeCommand(Message &currentMessage, std::size_t _currentOwnerID) = 0;
    virtual void initMapOfCommandHandler() = 0;
};

#endif //R_TYPE_IRFCHANDLER_HPP
