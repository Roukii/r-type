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
    state = std::make_shared<SplashState>(_info);
}

void	MenuState::menu(std::shared_ptr<IState> &state) {
}

void	MenuState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>(_info);
}

void	MenuState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>(_info);
}

void	MenuState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info);
}

void	MenuState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info);
}

int    MenuState::exec() {
    return lib->handleMenu();
}

void   MenuState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}
