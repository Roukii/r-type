//
// Created by Samy on 20/01/2018.
//

#ifndef R_TYPE_OPTIONS_HPP
#define R_TYPE_OPTIONS_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>

class Options {
    sf::Texture	_background;
    sf::Texture _cursor;
    sf::Sprite  _sprite[5];
    sf::Text		text[12];
    sf::Font		font;
    sf::SoundBuffer		_buffer;
    sf::Sound			_sound;
    int selected = 0;
public:
    Options();
    ~Options(){}

    sf::Text  *getText() {return text;};
    sf::Sprite *getSprite() {return _sprite;}
    void moveDown();
    void moveUp();
    int handleKeys(const sf::Event&e);
};


#endif //R_TYPE_OPTIONS_HPP
