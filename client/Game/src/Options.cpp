//
// Created by Samy on 20/01/2018.
//

#include "Options.hpp"

Options::Options() {
    if (!_background.loadFromFile("../assets/Stars.jpg"))
        throw ("error");
    _sprite[0].setTexture(_background);
    _sprite[0].setColor(sf::Color::Magenta);

    if (!_cursor.loadFromFile("../assets/HandCursor.gif"))
        throw ("error");
    _sprite[1].setTexture(_cursor);
    _sprite[1].setPosition(90 * 20 / 6, 580);

    if (!_buffer.loadFromFile("../assets/cursor.ogg"))
        throw ("error");
    _sound.setBuffer(_buffer);

    if (!font.loadFromFile("../assets/Enter-The-Grid.ttf"))
        throw ("error");

    text[0].setFont(font);
    text[0].setString("New Game");
    text[0].setCharacterSize(60);
    text[0].setPosition(sf::Vector2f(90 * 20 / 5, 550));

    text[1].setFont(font);
    text[1].setString("Options");
    text[1].setCharacterSize(60);
    text[1].setPosition(sf::Vector2f(90 * 20 / 5, 650));

    text[2].setFont(font);
    text[2].setString("Quit");
    text[2].setCharacterSize(60);
    text[2].setPosition(sf::Vector2f(90 * 20 / 5, 750));


    text[3].setFont(font);
    text[3].setString("R TYPE");
    text[3].setCharacterSize(200);
    text[3].setPosition(sf::Vector2f(90 * 20 / 2.8, 150));
}