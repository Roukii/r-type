//
// Created by Samy on 10/01/2018.
//

#include "MenuScreen.hpp"

#include <iostream>
#include "SplashScreen.hpp"
#include "GameScreen.hpp"
#include "OptionsScreen.hpp"

void	MenuScreen::splash(Core *core) {
    core->setState(screen<SplashScreen>());
    delete this;
}

void	MenuScreen::menu(Core *core) {
}

void	MenuScreen::options(Core *core) {
    core->setState(screen<OptionsScreen>());
    delete this;
}

void	MenuScreen::game(Core *core) {
    core->setState(screen<GameScreen>());
    delete this;
}

int    MenuScreen::exec(){
    std::cout << "MenuScreen" << std::endl;
}

void   MenuScreen::init() {

}