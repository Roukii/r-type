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
    delete this;
}

void	OptionsScreen::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuScreen>();
    delete this;
}

void	OptionsScreen::options(std::shared_ptr<IState> &state) {
}

void	OptionsScreen::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameScreen>();
    delete this;
}

int    OptionsScreen::exec() {
    std::cout << "OptionsScreen" << std::endl;
}

void   OptionsScreen::init() {

}