//
// Created by Samy on 10/01/2018.
//

#include <iostream>
#include "../include/SplashScreen.hpp"
#include "../include/MenuScreen.hpp"
#include "../include/GameScreen.hpp"
#include "../include/OptionsScreen.hpp"

void	SplashScreen::splash(std::shared_ptr<IState> &state) {
}

void	SplashScreen::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuScreen>();
    delete this;
}

void	SplashScreen::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsScreen>();
    delete this;
}

void	SplashScreen::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameScreen>();
    delete this;
}

int    SplashScreen::exec() {
    std::cout << "SplashScreen" << std::endl;
    return 0;
}

void   SplashScreen::init() {

}