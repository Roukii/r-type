//
// Created by Samy on 22/01/2018.
//

#include "ConnexionState.hpp"
#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "LobbyState.hpp"

void	ConnexionState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	ConnexionState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	ConnexionState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	ConnexionState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

void	ConnexionState::connexion(std::shared_ptr<IState> &state) {
}

void	ConnexionState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>();
}

int    ConnexionState::exec() {
    return lib->handleConnexion();
}

void   ConnexionState::init(std::shared_ptr<ILib> &lib, std::shared_ptr<CoreInfo> &info) {
    this->lib = lib;
    this->info = info;
}