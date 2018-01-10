//
// Created by Samy on 10/01/2018.
//


#include "OptionsScreen.hpp"

#include "MenuScreen.hpp"
#include <iostream>
#include "SplashScreen.hpp"
#include "GameScreen.hpp"

void	OptionsScreen::splash(Core *core) {
    core->setState(screen<SplashScreen>());
    delete this;
}

void	OptionsScreen::menu(Core *core) {
    core->setState(screen<MenuScreen>());
    delete this;
}

void	OptionsScreen::options(Core *core) {
}

void	OptionsScreen::game(Core *core) {
    core->setState(screen<GameScreen>());
    delete this;
}

int    OptionsScreen::exec() {
    std::cout << "OptionsScreen" << std::endl;
}

void   OptionsScreen::init() {

}