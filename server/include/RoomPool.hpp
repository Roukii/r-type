//
// Created by Alexandre on 21/01/2018.
//

#ifndef R_TYPE_ROOMPOOL_HPP
#define R_TYPE_ROOMPOOL_HPP

#include "Room.hpp"
#include "Random.h"
#include <memory>

#define PORT_MIN_RANGE 4000
#define PORT_MAX_RANGE 5000

namespace RTypeServer
{
    class RoomPool
    {
    public:
        RoomPool(unsigned int numberOfRoom);

        ~RoomPool();

        RoomPool(const RoomPool &) = delete;

        RoomPool &operator=(const RoomPool &) = delete;

    public:
        void startRooms();
        void shutdownRooms();
        void updateRooms();
    public:
        unsigned int _numberOfRoom;
        std::vector<std::shared_ptr<Room>> _rooms;
    };
}

#endif //R_TYPE_ROOMPOOL_HPP
