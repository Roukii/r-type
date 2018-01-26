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
    return -1;
}

void   OptionsState::init(std::shared_ptr<ILib> &lib, std::shared_ptr<CoreInfo> &info) {
    this->lib = lib;
    this->info = info;
}