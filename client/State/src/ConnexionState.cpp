//
// Created by Samy on 22/01/2018.
//

#include "ConnexionState.hpp"
#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "LobbyState.hpp"

void	ConnexionState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>(_info, engine);
}

void	ConnexionState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>(_info, engine);
}

void	ConnexionState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>(_info, engine);
}

void	ConnexionState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>(_info, engine);
}

void	ConnexionState::connexion(std::shared_ptr<IState> &state) {
}

void	ConnexionState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info, engine);
}

int    ConnexionState::exec() {
    return lib->handleConnexion();
}

void   ConnexionState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}