//
// Created by Samy on 22/01/2018.
//

#include "ConnexionState.hpp"
#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "LobbyState.hpp"
#include "ReadyState.hpp"

void ConnexionState::changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine) {
    if (s == "MENU")
        state = std::make_shared<MenuState>(info, engine);
    else if (s == "SPLASH")
        state = std::make_shared<SplashState>(info, engine);
    else if (s == "CONNEXION")
        state = std::make_shared<ConnexionState>(info, engine);
    else if (s == "OPTIONS")
        state = std::make_shared<OptionsState>(info, engine);
    else if (s == "LOBBY")
        state = std::make_shared<LobbyState>(info, engine);
    else if (s == "GAME")
        state = std::make_shared<GameState>(info, engine);
    else if (s == "READY")
        state = std::make_shared<ReadyState>(info, engine);
}

int    ConnexionState::exec() {
    return engine->_libGraph->handleConnexion();
}

void   ConnexionState::init() {
}