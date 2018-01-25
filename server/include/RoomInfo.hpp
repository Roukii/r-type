//
// Created by zozo on 25/01/18.
//

#ifndef R_TYPE_ROOMINFO_HPP
#define R_TYPE_ROOMINFO_HPP


#include <IServerUdpSocket.hpp>

namespace RTypeServer {
    class RoomInfo {
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> &_socket;
        unsigned short _port;
        char _nb_player;
        bool _ready[4];

    public:
        RoomInfo(std::shared_ptr<RTypeProtocol::IServerUdpSocket> &);

        ~RoomInfo() = default;

        RoomInfo(const RoomInfo &) = default;

        RoomInfo &operator=(const RoomInfo &) = default;

        unsigned short getPort() const { return _port; }

        char getNbPlayer() const { return _nb_player; }

        bool getReady(int nb) const {
            if (nb < 0 || nb > 3)
                return false;
            return _ready[nb];
        }

        void setPort(unsigned short p) { _port = p; }

        void addPlayer();

        void delPlayer(int nb);

        void setReady(int nb) { _ready[nb] = true; }

        void setNotReady(int nb) { _ready[nb] = false; }
    };
}

#endif //R_TYPE_ROOMINFO_HPP
