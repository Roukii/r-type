//
// Created by Samy on 10/01/2018.
//

#include "GameScreen.hpp"

#include <iostream>
#include "MenuScreen.hpp"
#include "SplashScreen.hpp"
#include "OptionsScreen.hpp"

void	GameScreen::splash(Core *core) {
    core->setState(screen<SplashScreen>());
    delete this;
}

void	GameScreen::menu(Core *core) {
    core->setState(screen<MenuScreen>());
    delete this;
}

void	GameScreen::options(Core *core) {
    core->setState(screen<OptionsScreen>());
    delete this;
}

void	GameScreen::game(Core *core) {
}

int    GameScreen::exec() {
    std::cout << "GameScreen" << std::endl;
}

void   GameScreen::init() {

}