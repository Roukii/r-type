//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_GAMEENGINE_HPP
#define R_TYPE_GAMEENGINE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "AEntity.hpp"
#include "EngineDefinitions.hpp"

namespace UgandaEngine {
    class AGameEngine {
        /*
         * Variables
         */
    private:
        //List of entities
        std::vector<AEntity> _Entities;

        /*
         * Constructor and destructor
         */
    public:
        AGameEngine();
        ~AGameEngine() = default;

        /*
         * Function and methods
         */
        //Start function
    public:
        void start();

        //Game Loop
        virtual void gameLoop() = 0;

        //Boolean to check loop condition
        virtual bool isAlive() = 0;

        //Generic functions to draw
        virtual void drawWindow() = 0;

        //Key handling
        virtual KeyInput input() = 0;

        //Event functions
        void update(float deltaTime, KeyInput keyInput);
        void addEntity(const AEntity &newEntity);
    };
}


#endif //R_TYPE_GAMEENGINE_HPP
