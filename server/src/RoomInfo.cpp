//
// Created by zozo on 25/01/18.
//

#include "RoomInfo.hpp"

namespace RTypeServer {
    RoomInfo::RoomInfo(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket) : _socket(socket)
    {
        _port = _socket.get()->getPort();
        _roomReady = false;
    }

    void RoomInfo::addPlayer(size_t id)
    {
        std::pair<size_t, bool>  p  = std::make_pair(id, false);
        _player.emplace_back(p);
    }

    void RoomInfo::delPlayer(size_t id)
    {
        int k = 0;
        for (auto i : _player)
        {
            i.second = false;
            if (i.first == id)
            {
                _player.erase(_player.begin() + k);
            }
            k++;
        }
    }

    void RoomInfo::playerReady(size_t id)
    {
        for (auto i : _player)
        {
            if (i.first == id)
            {
                i.second = true;
            }
        }
        for (auto i : _player)
        {
            if (i.second == false)
                return ;
        }
        _roomReady = true;
    }

    void RoomInfo::playerUnReady(size_t id)
    {
        for (auto i : _player)
        {
            if (i.first == id)
            {
                i.second = false;
            }
        }
        _roomReady = false;
    }
}