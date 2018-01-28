//
// Created by Samy on 10/01/2018.
//

#include "MenuState.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"

void	MenuState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>(_info, engine);
}

void	MenuState::menu(std::shared_ptr<IState> &state) {
}

void	MenuState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>(_info, engine);
}

void	MenuState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>(_info, engine);
}

void	MenuState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info, engine);
}

void	MenuState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info, engine);
}

int    MenuState::exec() {
    return lib->handleMenu();
}

void   MenuState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}
