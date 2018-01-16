//
// Created by Samy on 11/01/2018.
//

#include <iostream>
#include "../include/Menu.hpp"

Menu::Menu() {
    if (!_background.loadFromFile("../assets/Stars.jpg"))
        throw("error");
    _sprite[0].setTexture(_background);
    _sprite[0].setColor(sf::Color::Magenta);

    if (!_cursor.loadFromFile("../assets/HandCursor.gif"))
        throw("error");
    _sprite[1].setTexture(_cursor);
    _sprite[1].setPosition(90 * 20 / 6, 580);

    if (!_buffer.loadFromFile("../assets/cursor.ogg"))
        throw("error");
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

void    Menu::moveUp() {
    if (selected == 0) {
        _sprite[0].setColor(sf::Color::Cyan);
        _sprite[1].setPosition(90 * 20 / 6, 780);
        selected = 2;
    } else if (selected == 1) {
        _sprite[0].setColor(sf::Color::Magenta);
        _sprite[1].setPosition(90 * 20 / 6, 580);
        selected = 0;
    } else {
        _sprite[0].setColor(sf::Color::Green);
        _sprite[1].setPosition(90 * 20 / 6, 680);
        selected = 1;
    }
    this->_sound.play();
}

void    Menu::moveDown()
{
    if (selected == 0) {
        _sprite[0].setColor(sf::Color::Green);
        _sprite[1].setPosition(90 * 20 / 6, 680);
        selected = 1;
    } else if (selected == 1) {
        _sprite[0].setColor(sf::Color::Cyan);
        _sprite[1].setPosition(90 * 20 / 6, 780);
        selected = 2;
    } else {
        _sprite[0].setColor(sf::Color::Magenta);
        _sprite[1].setPosition(90 * 20 / 6, 580);
        selected = 0;
    }
    this->_sound.play();
}

int Menu::handleKeys(const sf::Event&e) {
    int ret = 1;
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Up) {
            moveUp();
        } else if (e.key.code == sf::Keyboard::Down) {
            moveDown();
        } else if (e.key.code == sf::Keyboard::Space) {
            if (selected == 0)
                ret = 3;
            else if (selected == 1)
                ret = 2;
            else
                exit(0);
        }
    }
    return ret;
}
