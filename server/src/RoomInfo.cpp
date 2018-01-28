//
// Created by zozo on 25/01/18.
//

#include <iostream>
#include "RoomInfo.hpp"

namespace RTypeServer {
    RoomInfo::RoomInfo(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket) : _socket(socket)
    {
        _port = _socket.get()->getPort();
        _roomReady = false;
    }

    void RoomInfo::addPlayer(std::size_t id)
    {
        std::pair<std::size_t, bool>  p  = std::make_pair(id, false);
        _player.emplace_back(p);
    }

    void RoomInfo::delPlayer(std::size_t id)
    {
        for (int i = 0; i < _player.size(); i++)
        {
            _player[i].second = false;
            if (_player[i].first == id)
                _player.erase(_player.begin() + i);
        }
    }

    void RoomInfo::playerReady(std::size_t id)
    {
        for (int i = 0; i < _player.size(); i++)
        {
            if (_player[i].first == id)
                _player[i].second = true;
        }
        for (auto i : _player)
        {
            if (i.second == false)
                return;
        }
        _roomReady = true;
    }

    void RoomInfo::playerUnReady(std::size_t id)
    {
        for (int i = 0; i < _player.size(); i++)
        {
            if (_player[i].first == id)
                _player[i].second = false;
        }
        _roomReady = false;
    }
}