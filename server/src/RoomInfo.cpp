//
// Created by zozo on 25/01/18.
//

#include "RoomInfo.hpp"

namespace RTypeServer {
    RoomInfo::RoomInfo(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &socket) : _socket(socket)
    {
        _port = socket.get()->getPort();
        _nb_player = socket.get()->getClients();
        for (int i = 0; i < 4; i++)
            _ready[i] = socket.get()->getReady(i);
    }

    void RoomInfo::addPlayer() {

    }

    void RoomInfo::delPlayer(int nb) {

    }
}