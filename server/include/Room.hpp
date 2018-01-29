//
// Created by Alexandre on 21/01/2018.
//

#ifndef R_TYPE_ROOM_HPP
#define R_TYPE_ROOM_HPP

#include <memory>
#include <thread>
#include <cstdlib>
#include <chrono>

#include "ServerUdp.hpp"
#include "RFCServerRoomHandler.hpp"
#include "RFCGameHandler.hpp"

#define FRAME_RATE 5

namespace RTypeServer
{
    enum RoomState
    {
        WAITING_STATE = 0,
        PLAYING_STATE
    };

    class Room
    {
    public:
        Room(unsigned short port);

        ~Room();

        Room(const Room &r) = delete;

        Room &operator=(const Room &) = delete;

    public:
        void startRoom();
        bool isRunning();
        void shutdown();
        RoomState getState() const;
        void updateWaitingRoom();

    public:

        unsigned short getPort() const {
            return _roomServer.get()->getPort();
        }
        char getPlayer() const {
            return _roomServer.get()->getClients();
        }
        bool getReady(int nb) const {
            return _roomServer.get()->getReady(nb);
        }

    private:
        void runGame();
        void startGame();

    private:
        std::thread _serviceThread;
        MessageQueue<RTypeProtocol::Message>    _messageQueue;
        std::shared_ptr<RTypeProtocol::IServerUdpSocket> _roomServer;
        RFCServerRoomHandler _rfcHandler;
        bool _running;
        RoomState _state;
    };
}

#endif //R_TYPE_ROOM_HPP
