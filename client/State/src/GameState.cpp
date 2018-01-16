//
// Created by Samy on 10/01/2018.
//

#include "../include/GameState.hpp"

#include <iostream>
#include "../include/MenuState.hpp"
#include "../include/SplashState.hpp"
#include "../include/OptionsState.hpp"

void	GameState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	GameState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	GameState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	GameState::game(std::shared_ptr<IState> &state) {
}

int    GameState::exec(sf::RenderWindow &win) {
    std::cout << "GameScreen" << std::endl;
    return -1;
}

void   GameState::init() {

}