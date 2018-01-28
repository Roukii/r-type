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
    std::vector<char> actions = lib->handleClientAction();
    int opt = lib->handleChangeOption();

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
    lib->handleOption();
    return -1;
}

void   OptionsState::init(std::shared_ptr<ILib> &lib) {
    this->lib = lib;
}