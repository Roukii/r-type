//
// Created by Alexandre on 21/01/2018.
//

#include "Game.hpp"
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
        std::vector<UgandaEngine::Entity> entityList;
        RFCGameHandler gameHandler(_roomServer, entityList);
        RTypeGame::Game game;
//        game.init();

        while(_roomServer.get()->isRunning())
        {
            auto current = std::chrono::system_clock::now();

            if (!_messageQueue.isEmpty())
            {
                gameHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
                _messageQueue.pop();
            }

            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - current;

            game.play(elapsed_seconds.count(), _roomServer);
            ++game._ticks;
            if (game._ticks > (20 * 20))
                //TODO: remettre à 1
                game._ticks = 2;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FRAME_RATE));
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
            _rfcHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
            _messageQueue.pop();
            if (_rfcHandler.getRoomInfo().getRoomReady())
            {
                _state = RoomState::PLAYING_STATE;
                _serviceThread = std::thread(&Room::runGame, this);
                RTypeProtocol::Message msg;
                msg._msg.get()->_header._code = RTypeProtocol::START_GAME;
                _roomServer.get()->SendToAll(msg);
            }
        }
    }

    void Room::startGame()
    {
        _serviceThread = std::thread(&Room::runGame, this);
    }
}