//
// Created by Alexandre on 21/01/2018.
//

#include "Room.hpp"

namespace RTypeServer
{
    Room::Room(unsigned short port)
            : _roomServer(std::make_shared<ServerUdp>(_messageQueue, port)),
              _running(false),
              _state(RoomState::WAITING_STATE),
              _rfcHandler(_roomServer)
    {}

    Room::~Room()
    {
        _roomServer.get()->shutdown();
    }

    void Room::runGame()
    {
        while(_roomServer.get()->isRunning())
        {
            if (!_messageQueue.isEmpty())
            {
                _rfcHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
                _messageQueue.pop();
            }
        }
    }

    void Room::startRoom()
    {
        _running = true;
        _roomServer.get()->runServerWithThread();
    }

    bool Room::isRunning()
    {
        return _running;
    }

    void Room::shutdown()
    {
        _roomServer.get()->shutdown();
    }

    RoomState Room::getState() const
    {
        return _state;
    }

    void Room::updateWaitingRoom()
    {
        while (!_messageQueue.isEmpty())
        {
            std::cout << "a room was updated" << std::endl;
            _rfcHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
            _messageQueue.pop();
        }
    }

    void Room::startGame()
    {
        _serviceThread = std::thread(&Room::runGame, this);
    }
}