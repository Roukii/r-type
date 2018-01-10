//
// Created by Samy on 10/01/2018.
//

#include "../include/GameScreen.hpp"

#include <iostream>
#include "../include/MenuScreen.hpp"
#include "../include/SplashScreen.hpp"
#include "../include/OptionsScreen.hpp"

void	GameScreen::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashScreen>();
}

void	GameScreen::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuScreen>();
}

void	GameScreen::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsScreen>();
}

void	GameScreen::game(std::shared_ptr<IState> &state) {
}

int    GameScreen::exec() {
    std::cout << "GameScreen" << std::endl;
    return 0;
}

void   GameScreen::init() {

}