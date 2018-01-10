//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_GAMEENGINE_HPP
#define R_TYPE_GAMEENGINE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "AEntity.hpp"

namespace UgandaEngine {
    class GameEngine {
        /*
         * Variables
         */
    private:
        //Window
        sf::RenderWindow _Window;

        //Background's sprite and texture
        sf::Sprite _BgSprite;
        sf::Texture _BgTexture;

        //List of entities
        std::vector<AEntity> _Entities;

        /*
         * Constructor and destructor
         */
    public:
        GameEngine();
        ~GameEngine() = default;

        /*
         * Function and methods
         */
        //Start function
    public:
        void start();

        //Input functions
        void input();

        //Drawing functions
        void draw();

        //Event functions
        void update(float deltaTime);
    };
}


#endif //R_TYPE_GAMEENGINE_HPP
