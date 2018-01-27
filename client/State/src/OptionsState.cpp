//
// Created by Samy on 10/01/2018.
//

#include "OptionsState.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"

void	OptionsState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>(_info);
}

void	OptionsState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>(_info);
}

void	OptionsState::options(std::shared_ptr<IState> &state) {
}

void	OptionsState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>(_info);
}

void	OptionsState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info);
}

void	OptionsState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info);
}

int    OptionsState::exec() {
    return lib->handleOption();
}

void   OptionsState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}