//
// Created by zozo on 18/01/18.
//

#ifndef R_TYPE_RFCHANDLER_HPP
#define R_TYPE_RFCHANDLER_HPP

#include <iostream>
#include <map>

namespace RTypeServer
{
    enum code {
        ERR = 1,
        OK,
        LOGIN,
        STATUS,
        WAITING,
        NEWENTITY,
        MOVENTITY,
        DELENTITY,
        NBROOM,
        NBPLAYERROOM,
        MAXNBROOM,
        NEWGAME,
        ENDGAME,
    };


    struct header
    {
        char _code;
        char _owner;
    };

    struct error
    {
        char _errornb;
    };

    struct status
    {
        char _id[4];
        char _username[16];
        char _stat;
    };

    struct pos
    {
        int _x;
        int _y;
    };

    struct entity
    {
        pos _pos;
        char id[4];
    };

    struct msg
    {
        header _header;
        union Data
        {
            error _error;
            status _status;
            entity _entity;
        } data;
    };

    class RFCHandler
    {
        typedef void (RFCHandler::*function)();
        using mapOfCommand = std::map<RTypeServer::code, function>;

    public:
        RFCHandler() {initMapOfCommandHandler();}
        ~RFCHandler() {}
        RFCHandler(const RFCHandler &) = delete;
        RFCHandler &operator=(const RFCHandler &) = delete;

        void initMapOfCommandHandler();

        void RFCError();
        void RFCOk();
        void RFCLogin();
        void RFCStatus();
        void RFCNewEntity();
        void RFCMovEntity();
        void RFCDelEntity();

    private:
        mapOfCommand _CommandHandler;
    };

}

#endif //R_TYPE_RFCHANDLER_HPP
