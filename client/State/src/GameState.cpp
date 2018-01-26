//
// Created by Samy on 10/01/2018.
//

#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"


void	GameState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	GameState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	GameState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	GameState::game(std::shared_ptr<IState> &state) {
}

void	GameState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>();
}

void	GameState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>();
}

int    GameState::exec() {
    return -1;
}

void   GameState::init(std::shared_ptr<ILib> &lib, std::shared_ptr<CoreInfo> &info) {
    this->lib = lib;
    this->info = info;
}