//
// Created by zozo on 25/01/18.
//

#ifndef R_TYPE_ROOMINFO_HPP
#define R_TYPE_ROOMINFO_HPP


#include <IServerUdpSocket.hpp>
#include <vector>

namespace RTypeServer {
    class RoomInfo {
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        unsigned short _port;
        std::vector<std::pair<size_t, bool>> _player;
        bool _roomReady;

    public:
        RoomInfo(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &);

        ~RoomInfo() = default;

        RoomInfo(const RoomInfo &) = default;

        RoomInfo &operator=(const RoomInfo &) = default;

        unsigned short getPort() const { return _port; }

        void setPort(unsigned short p) { _port = p; }

        void addPlayer(size_t);

        void delPlayer(size_t);

        std::vector<std::pair<size_t, bool>> getPlayers() const {return _player;};

        void playerReady(size_t id);

        void playerUnReady(size_t id);

        bool getRoomReady() const { return _roomReady; }
    };
}

#endif //R_TYPE_ROOMINFO_HPP
