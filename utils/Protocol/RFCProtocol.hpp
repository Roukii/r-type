//
// Created by Alexandre on 20/01/2018.
//

#ifndef R_TYPE_RFCPROTOCOL_HPP
#define R_TYPE_RFCPROTOCOL_HPP

namespace RTypeProtocol
{
    enum code
    {
        ERR = 1,
        OK,
        STATUS,
        CONNECT,
        NEW_ENTITY,
        MOV_ENTITY,
        DEL_ENTITY,
        ROOMS,
        JOIN_ROOM,
        INFO_ROOM,
        PLAYER_JOIN_ROOM,
        READY_ROOM,
        START_GAME,
        END_OF_GAME
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
        char _x[4];
        char _y[4];
    };

    struct entity
    {
        pos _pos;
        char id[4];
    };

    struct room
    {
        char _port[4];
        char _nb_player;
        bool _player_ready[4];
    };

    struct msg
    {
        header _header;
        union Data
        {
            error _error;
            status _status;
            entity _entity;
            room _room;
        } data;
    };
}

#endif //R_TYPE_RFCPROTOCOL_HPP
