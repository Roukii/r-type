//
// Created by Alexandre on 20/01/2018.
//

#ifndef R_TYPE_RFCPROTOCOL_HPP
#define R_TYPE_RFCPROTOCOL_HPP

#pragma pack(push, 1)

namespace RTypeProtocol
{
    enum code
    {
        ERR = 0,
        OK,
        STATUS,
        CONNECT,
        NEW_ENTITY,
        MOV_ENTITY,
        DEL_ENTITY,
        ACTION,
        ROOMS,
        INFO_ROOM,
        PLAYER_JOIN_ROOM,
        PLAYER_LEAVE_ROOM,
        PLAYER_READY,
        PLAYER_NOT_READY,
        READY_ROOM,
        START_GAME,
        END_OF_GAME
    };

    enum actions
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT,
        SHOOT,
        LEAVE
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
        char _port[2];
        char _nb_player;
        bool _player_ready[4];
    };

    struct nb_room
    {
        char _room[4];
    };

    struct action
    {
        char _action;
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
            nb_room _nb_room;
            action _action;
        } data;
    };

#pragma pack(pop)
}

#endif //R_TYPE_RFCPROTOCOL_HPP