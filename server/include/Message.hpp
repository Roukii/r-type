//
// Created by zozo on 19/01/18.
//

#ifndef R_TYPE_MESSAGE_HPP
#define R_TYPE_MESSAGE_HPP

#include "RFCHandler.hpp"

namespace RTypeServer {
    class Message {

    public:
        Message() : _msg(new RTypeServer::msg) {}
        ~Message() {delete _msg;}
        Message(const Message &) = delete;
        Message &operator=(const Message &) = delete;

        const size_t getSizeMsg() const {return _sizeMsg;}
        void setSizeMsg(size_t size) { _sizeMsg = size;}

        RTypeServer::msg *_msg;
    private:
        size_t _sizeMsg;

    };
}

#endif //R_TYPE_MESSAGE_HPP
