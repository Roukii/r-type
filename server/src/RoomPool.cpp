//
// Created by Alexandre on 21/01/2018.
//

#include "RoomPool.hpp"

namespace RTypeServer
{
    RoomPool::RoomPool(unsigned int numberOfRoom)
    : _numberOfRoom(numberOfRoom)
    {}

    RoomPool::~RoomPool()
    {
        shutdownRooms();
    }

    void RoomPool::startRooms()
    {
        Random<unsigned short> _rand;

        for (unsigned int i = 0; i < _numberOfRoom; i++)
        {
            unsigned short port = ServerUdp::createAPort();
            std::shared_ptr<Room> newRoom = std::make_shared<Room>(port);
            _rooms.push_back(newRoom);
            newRoom.get()->startRoom();
        }
    }

    void RoomPool::shutdownRooms()
    {
        for (auto &_room : _rooms)
        {
            _room.get()->shutdown();
        }
    }

    void RoomPool::updateRooms()
    {
        for (auto &_room : _rooms)
        {
            if (_room.get()->getState() == RoomState::WAITING_STATE)
                _room.get()->updateWaitingRoom();
        }
    }

}