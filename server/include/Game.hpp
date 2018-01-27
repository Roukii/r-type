//
// Created by sentrance on 26/01/18.
//

#ifndef R_TYPE_GAME_HPP
#define R_TYPE_GAME_HPP


#include <vector>
#include <include/Entity.hpp>

namespace RTypeGame {
    class Game {
        /*
         * Variables
         */
        std::vector<UgandaEngine::entity::Entity> _entities;

        /*
         * Constructor and destructor
         */
    public:
        Game() = default;
        ~Game() = default;

        /*
         * Function and methods
         */
    public:
        void init();
        void play(double elapsedTime);

    private:
        void updateWorld();
    };
}


#endif //R_TYPE_GAME_HPP
