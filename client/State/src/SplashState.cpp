//
// Created by Samy on 10/01/2018.
//

#include "SplashState.hpp"
#include "GameState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"


void	SplashState::splash(std::shared_ptr<IState> &state) {}

void	SplashState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	SplashState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	SplashState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

void	SplashState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>();
}

void	SplashState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>();
}

int    SplashState::exec() {
    return -1;
}

void   SplashState::init(std::shared_ptr<ILib> &lib) {
}