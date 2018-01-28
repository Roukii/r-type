//
// Created by sentrance on 26/01/18.
//

#ifndef R_TYPE_GAME_HPP
#define R_TYPE_GAME_HPP


#include <vector>
#include "IServerUdpSocket.hpp"
#include "include/Entity.hpp"
#include "include/AGameEngine.hpp"
#include "AGameEntity.hpp"
#include "Ship.hpp"
#include "Bullet.hpp"

namespace RTypeGame {
    class Game {
        /*
         * Variables
         */
    private:
        std::shared_ptr<UgandaEngine::AGameEngine> _engine;
        std::vector<RTypeGame::AGameEntity> _entities;

    public:
        int _nbrPlayers;
        int _ticks;

        /*
         * Constructor and destructor
         */
    public:
        Game() : _nbrPlayers(0), _ticks(1) {}
        ~Game() = default;

        /*
         * Function and methods
         */
    public:
        void init();
        void play(double elapsedTime, const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room);

    private:
        bool checkCollision(const RTypeGame::AGameEntity &entity1, const RTypeGame::AGameEntity &entity2);
        bool checkOutOfBound(const RTypeGame::AGameEntity &entity);
        RTypeProtocol::Message createMsgDelE(int id);
        RTypeProtocol::Message createMsgMoveE(int id);
        RTypeProtocol::Message createMsgNewE(Ship, RTypeProtocol::types type);
        Ship createNewEnnemy();
    };
}


#endif //R_TYPE_GAME_HPP
