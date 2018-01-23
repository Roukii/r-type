//
// Created by Samy on 22/01/2018.
//

#include "LobbyState.hpp"
#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"


void	LobbyState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	LobbyState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	LobbyState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	LobbyState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

void	LobbyState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>();
}

void	LobbyState::lobby(std::shared_ptr<IState> &state) {
}

int    LobbyState::exec() {
    sf::Event event;
    while (lib->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            lib->getWindow()->close();
    }
    lib->getWindow()->clear();

    lib->getWindow()->draw(*lib->getSprite("Background1"));
    lib->getWindow()->display();
}

void   LobbyState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}