//
// Created by Samy on 10/01/2018.
//

#include "OptionsState.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"

void	OptionsState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>(_info, engine);
}

void	OptionsState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>(_info, engine);
}

void	OptionsState::options(std::shared_ptr<IState> &state) {
}

void	OptionsState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>(_info, engine);
}

void	OptionsState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info, engine);
}

void	OptionsState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info, engine);
}

int    OptionsState::exec() {
    return lib->handleOption();
}

void   OptionsState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}