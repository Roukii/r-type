//
// Created by Samy on 10/01/2018.
//

#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"


void	GameState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>(_info);
}

void	GameState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>(_info);
}

void	GameState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>(_info);
}

void	GameState::game(std::shared_ptr<IState> &state) {
}

void	GameState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info);
}

void	GameState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info);
}

int    GameState::exec() {
//    double previous = getCurrentTime();
//    double lag = 0.0;
//    while (true)
//    {
//        double current = getCurrentTime();
//        double elapsed = current - previous;
//        previous = current;
//        lag += elapsed;
//
//        processInput();
//
//        while (lag >= MS_PER_UPDATE)
//        {
//            update();
//            lag -= MS_PER_UPDATE;
//        }
//
//        render(lag / MS_PER_UPDATE);
//    }
    return -1;
}

void   GameState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}