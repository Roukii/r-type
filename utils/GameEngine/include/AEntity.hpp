//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "EngineDefinitions.hpp"

//TODO: ajouté des booléens pour voir si l'entité est hurtable (si elle prend des dégâts) ou si elle heurt en touchant

namespace AUgandaEngine {
    class AEntity {
        /*
         * Variables
         */
    protected:
        //Entity data
        sf::Vector2f _Position;
        sf::Sprite _Sprite;
        sf::Texture _Texture;

        //Speed
        float _Speed;

        /*
         * Constructors / Destructor
         */
        AEntity() : _Speed(0) {};
        virtual ~AEntity() = default;

        /*
         * Function and methods
         */
    public:
        //Getters and setters
        sf::Sprite getSprite() { return _Sprite; }

        //Moving functions. Position should have the calcul: pos += _Speed * elapsedTime.
        virtual void move(const sf::Vector2f newPos) = 0;

        //Update Entity function
        virtual void update(float elapsedTime, KeyInput keyInput) = 0;
    };
}


#endif //R_TYPE_AENTITY_HPP
