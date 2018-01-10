//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_AENTITY_HPP
#define R_TYPE_AENTITY_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace UgandaEngine {
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
        virtual void move(const sf::Vector2f newPos);

        //Update Entity function
        virtual void update(float elapsedTime);
    };
}


#endif //R_TYPE_AENTITY_HPP
