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
    delete this;
}

void	GameScreen::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuScreen>();
    delete this;
}

void	GameScreen::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsScreen>();
    delete this;
}

void	GameScreen::game(std::shared_ptr<IState> &state) {
}

int    GameScreen::exec() {
    std::cout << "GameScreen" << std::endl;
}

void   GameScreen::init() {

}