//
// Created by Samy on 10/01/2018.
//


#include "OptionsState.hpp"

#include "SplashState.hpp"
#include "GameState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"

void	OptionsState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	OptionsState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	OptionsState::options(std::shared_ptr<IState> &state) {
}

void	OptionsState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

void	OptionsState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>();
}

void	OptionsState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>();
}

int    OptionsState::exec() {
    sf::Event event;
    while (lib->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            lib->getWindow()->close();
    }
    lib->getWindow()->clear();

    lib->getWindow()->draw(*lib->getSprite("Background1"));
    lib->getWindow()->display();
    return -1;
}

void   OptionsState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}