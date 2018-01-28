//
// Created by Samy on 10/01/2018.
//

#include "OptionsState.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"

void OptionsState::changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine) {
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
}

int    OptionsState::exec() {
    std::vector<char> actions = engine->_libGraph->handleClientAction();
    int opt = engine->_libGraph->handleChangeOption();

    for (auto e : actions) {
        std::cout << "get action" << std::endl;
        if (e == 27)
            return 1;
        //TODO : interpret the action and get UP, DOWN, RIGHT, LEFT, SHOOT, LEAVE
        // il faut faire une récupération des touches dans le state option
        if (opt == 1)
            myKeys->up = e;
        else if (opt == 2)
            myKeys->down = e;
        else if (opt == 3)
            myKeys->left = e;
        else if (opt == 4)
            myKeys->right = e;
        else if (opt == 5)
            myKeys->shoot = e;
    }
    engine->_libGraph->handleOption();
    return -1;
}

void   OptionsState::init() {
}