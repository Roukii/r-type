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
    return lib->handleLobby();
}

void   LobbyState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}