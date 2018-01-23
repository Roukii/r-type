//
// Created by Samy on 10/01/2018.
//

#include "MenuState.hpp"

#include "SplashState.hpp"
#include "GameState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"

void	MenuState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	MenuState::menu(std::shared_ptr<IState> &state) {
}

void	MenuState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	MenuState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

void	MenuState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>();
}

void	MenuState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>();
}

int    MenuState::exec() {
    sf::Event event;
    int ret;
    while (lib->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            lib->getWindow()->close();
        if ((ret = handleKeys(event)) != 1)
            return ret;
    }
    lib->getWindow()->clear();

    lib->getWindow()->draw(*lib->getSprite("Background1"));
    lib->getWindow()->draw(*lib->getSprite("Cursor1"));
    lib->getWindow()->draw(*lib->getText("New Game"));
    lib->getWindow()->draw(*lib->getText("Options"));
    lib->getWindow()->draw(*lib->getText("Quit"));
    lib->getWindow()->draw(*lib->getText("R TYPE"));
    lib->getWindow()->display();
    return -1;
}

void   MenuState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}

void    MenuState::moveUp() {
    if (selected == 0) {
        (*lib->getSprite("Background1")).setColor(sf::Color::Red);
        (*lib->getSprite("Cursor1")).setPosition(90 * 20 / 6, 780);
        selected = 2;
    } else if (selected == 1) {
        (*lib->getSprite("Background1")).setColor(sf::Color::Magenta);
        (*lib->getSprite("Cursor1")).setPosition(90 * 20 / 6, 580);
        selected = 0;
    } else {
        (*lib->getSprite("Background1")).setColor(sf::Color::Green);
        (*lib->getSprite("Cursor1")).setPosition(90 * 20 / 6, 680);
        selected = 1;
    }
    (*lib->getSound("Cursor2")).play();
}

void    MenuState::moveDown()
{
    if (selected == 0) {
        (*lib->getSprite("Background1")).setColor(sf::Color::Green);
        (*lib->getSprite("Cursor1")).setPosition(90 * 20 / 6, 680);
        selected = 1;
    } else if (selected == 1) {
        (*lib->getSprite("Background1")).setColor(sf::Color::Red);
        (*lib->getSprite("Cursor1")).setPosition(90 * 20 / 6, 780);
        selected = 2;
    } else {
        (*lib->getSprite("Background1")).setColor(sf::Color::Magenta);
        (*lib->getSprite("Cursor1")).setPosition(90 * 20 / 6, 580);
        selected = 0;
    }
    (*lib->getSound("Cursor2")).play();
}

int MenuState::handleKeys(const sf::Event&e) {
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
                ret = -2;
        }
    }
    return ret;
}
