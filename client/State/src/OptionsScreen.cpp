//
// Created by Samy on 10/01/2018.
//


#include "../include/OptionsScreen.hpp"

#include "../include/MenuScreen.hpp"
#include <iostream>
#include "../include/SplashScreen.hpp"
#include "../include/GameScreen.hpp"

void	OptionsScreen::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashScreen>();
}

void	OptionsScreen::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuScreen>();
}

void	OptionsScreen::options(std::shared_ptr<IState> &state) {
}

void	OptionsScreen::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameScreen>();
}

int    OptionsScreen::exec() {
    std::cout << "OptionsScreen" << std::endl;
    return 0;
}

void   OptionsScreen::init() {

}