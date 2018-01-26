//
// Created by zozo on 25/01/18.
//

#include "RoomInfo.hpp"

namespace RTypeServer {
    RoomInfo::RoomInfo(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket) : _socket(socket)
    {
        _port = _socket.get()->getPort();
        _nb_player = _socket.get()->getClients();
        for (int i = 0; i < 4; i++)
            _ready[i] = _socket.get()->getReady(i);
    }

    void RoomInfo::addPlayer() {
        ++_nb_player;

    }

    void RoomInfo::delPlayer() {
        for (bool &i : _ready)
            i = false;
        --_nb_player;
    }
}