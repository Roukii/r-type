//
// Created by Samy on 28/01/2018.
//

#ifndef R_TYPE_RTYPEEXCEPTION_HPP
#define R_TYPE_RTYPEEXCEPTION_HPP

#include <exception>
#include <string>

class RTypeException : public std::exception
{
public:
    RTypeException(const std::string &e) throw() : message(e) {}
    ~RTypeException() throw() {}

    const char* what() const throw() { return message.c_str();}

protected:
    const std::string message;
};
#endif //R_TYPE_RTYPEEXCEPTION_HPP
