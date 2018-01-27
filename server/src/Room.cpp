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
        std::vector<UgandaEngine::entity::Entity> testo;
        RFCGameHandler gameHandler(_roomServer, testo);
        RTypeGame::Game game;
        game.init();

        while(_roomServer.get()->isRunning())
        {
            if (!_messageQueue.isEmpty())
            {
                gameHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
                _messageQueue.pop();
            }
            auto current = std::chrono::system_clock::now();

            //Ici boucle de jeu
//            _roomServer.get()->SendToAllExcept();

            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - current;

            game.play(elapsed_seconds.count());

            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FRAME_RATE));
            std::cout << "Elapsed time : " << elapsed_seconds.count() << std::endl;
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
            if (_rfcHandler.getRoomInfo().getRoomReady())
            {
                _state = RoomState::PLAYING_STATE;
                _serviceThread = std::thread(&Room::runGame, this);
            }
        }
    }

    void Room::startGame()
    {
        _serviceThread = std::thread(&Room::runGame, this);
    }
}