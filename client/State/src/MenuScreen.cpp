//
// Created by Samy on 10/01/2018.
//

#include "../include/MenuScreen.hpp"

#include <iostream>
#include "../include/SplashScreen.hpp"
#include "../include/GameScreen.hpp"
#include "../include/OptionsScreen.hpp"

void	MenuScreen::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashScreen>();
    delete this;
}

void	MenuScreen::menu(std::shared_ptr<IState> &state) {
}

void	MenuScreen::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsScreen>();
    delete this;
}

void	MenuScreen::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameScreen>();
    delete this;
}

int    MenuScreen::exec(){
    std::cout << "MenuScreen" << std::endl;
}

void   MenuScreen::init() {

}