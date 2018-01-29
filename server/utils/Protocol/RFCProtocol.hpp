//
// Created by Alexandre on 20/01/2018.
//

#ifndef R_TYPE_RFCPROTOCOL_HPP
#define R_TYPE_RFCPROTOCOL_HPP

#pragma pack(push, 1)

namespace RTypeProtocol
{
    enum types
    {
        SHIP,
        BULLET,
        ENNEMY
    };
    enum code
    {
        ERR = 0,
        OK,
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
    };

    struct error
    {
        char _errornb;
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
        char type;
    };

    struct room
    {
        char _port[2];
        char _nb_player;
        bool _player_ready[4];
        bool _playing;
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
            entity _entity;
            room _room;
            action _action;
        } data;
    };

#pragma pack(pop)
}

#endif //R_TYPE_RFCPROTOCOL_HPP
