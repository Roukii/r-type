//
// Created by Samy on 10/01/2018.
//

#include <iostream>
#include "../include/SplashState.hpp"
#include "../include/MenuState.hpp"
#include "../include/GameState.hpp"
#include "../include/OptionsState.hpp"

void	SplashState::splash(std::shared_ptr<IState> &state) {}

void	SplashState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	SplashState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	SplashState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

int    SplashState::exec(sf::RenderWindow &win) {
    std::cout << "SplashScreen" << std::endl;
    return -1;
}

void   SplashState::init() {}