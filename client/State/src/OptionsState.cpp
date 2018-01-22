//
// Created by Samy on 10/01/2018.
//


#include "../include/OptionsState.hpp"

#include "../include/MenuState.hpp"
#include <iostream>
#include "../include/SplashState.hpp"
#include "../include/GameState.hpp"

void	OptionsState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	OptionsState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>();
}

void	OptionsState::options(std::shared_ptr<IState> &state) {
}

void	OptionsState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

int    OptionsState::exec(std::shared_ptr<sf::RenderWindow> win) {
    std::cout << "OptionsScreen" << std::endl;
    return -1;
}

void   OptionsState::init() {

}