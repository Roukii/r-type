//
// Created by Samy on 10/01/2018.
//

#include <iostream>
#include "SplashScreen.hpp"
#include "MenuScreen.hpp"
#include "GameScreen.hpp"
#include "OptionsScreen.hpp"

void	SplashScreen::splash(Core *core) {
}

void	SplashScreen::menu(Core *core) {
    core->setState(screen<MenuScreen>());
    delete this;
}

void	SplashScreen::options(Core *core) {
    core->setState(screen<OptionsScreen>());
    delete this;
}

void	SplashScreen::game(Core *core) {
    core->setState(screen<GameScreen>());
    delete this;
}

int    SplashScreen::exec() {
    std::cout << "SplashScreen" << std::endl;
}

void   SplashScreen::init() {

}