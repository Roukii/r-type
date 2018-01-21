//
// Created by zozo on 19/01/18.
//

#ifndef R_TYPE_MESSAGE_HPP
#define R_TYPE_MESSAGE_HPP

#include "RFCProtocol.hpp"
#include <string>

class Message {

public:
    Message() : _msg(new msg) {}
    ~Message() = default;

    Message(const Message &o) : _msg(new msg), _sizeMsg(o._sizeMsg)
    {
        _msg.get()->_header = o._msg.get()->_header;
        _msg.get()->data = o._msg.get()->data;
    }

    Message &operator=(const Message &o)
    {
        if (this != &o)
        {
            _msg.get()->_header = o._msg.get()->_header;
            _msg.get()->data = o._msg.get()->data;
            _sizeMsg = o.getSizeMsg();
        }
        return *this;
    };

    const std::size_t getSizeMsg() const {return _sizeMsg;}
    void setSizeMsg(std::size_t size) { _sizeMsg = size;}

    std::shared_ptr<msg> _msg;

private:
    std::size_t _sizeMsg;

};

#endif //R_TYPE_MESSAGE_HPP
