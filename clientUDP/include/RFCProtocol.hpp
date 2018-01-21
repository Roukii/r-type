//
// Created by Alexandre on 20/01/2018.
//

#ifndef R_TYPE_RFCPROTOCOL_HPP
#define R_TYPE_RFCPROTOCOL_HPP

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

#endif //R_TYPE_RFCPROTOCOL_HPP
