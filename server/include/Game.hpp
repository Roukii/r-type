//
// Created by sentrance on 26/01/18.
//

#ifndef R_TYPE_GAME_HPP
#define R_TYPE_GAME_HPP


#include <vector>
#include "IServerUdpSocket.hpp"
#include "AGameEngine.hpp"
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

    public:
        std::vector<RTypeGame::AGameEntity> _entities;
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
        void init(const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room);
        void play(double elapsedTime, const std::shared_ptr<RTypeProtocol::IServerUdpSocket> &room);
        Bullet createNewBullet(const AGameEntity &entity);
        Ship createNewEnnemy();
        Ship createNewPlayer();

    private:
        bool checkCollision(const RTypeGame::AGameEntity &entity1, const RTypeGame::AGameEntity &entity2);
        bool checkOutOfBound(const RTypeGame::AGameEntity &entity);
        RTypeProtocol::Message createMsgDelE(int id);
        RTypeProtocol::Message createMsgMoveE(AGameEntity gameEntity);
        RTypeProtocol::Message createMsgNewE(AGameEntity gameEntity, RTypeProtocol::types type);
    };
}


#endif //R_TYPE_GAME_HPP
