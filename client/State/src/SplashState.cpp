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
    state = std::make_shared<MenuState>(_info, engine);
}

void	SplashState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>(_info, engine);
}

void	SplashState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>(_info, engine);
}

void	SplashState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info, engine);
}

void	SplashState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info, engine);
}

int    SplashState::exec() {
    return lib->handleSplash();
}

void   SplashState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}