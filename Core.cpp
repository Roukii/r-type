//
// Created by Samy on 10/01/2018.
//

#include <stdio.h>
#include <iostream>
#include "Core.hpp"
#include "SplashScreen.hpp"


//void	Core::initLib(int x, int y)
//{
//    ILib *(*external_creator)(int, int);
//    _handle = dlopen("./lib/lib_zappy_sfml.so", RTLD_LAZY);
//    if (_handle == NULL)
//        throw("[X]Failed to dlopen.");
//    external_creator = reinterpret_cast<ILib *(*)(int, int)>(dlsym(_handle, "create_lib_sfml"));
//    if (external_creator == NULL)
//        throw("[X]Fail to create external_creator.");
//    _gpm_g->setLib(external_creator(x, y));
//}

void    Core::start() {
    this->_state = new SplashScreen();
    while (1) {
        _state->exec();
        std::string lol;
        getline(std::cin, lol);
        if (lol == "splash")
            _state->splash(this);
        else if (lol == "menu")
            _state->menu(this);
        else if (lol == "options")
            _state->options(this);
        else if (lol == "game")
            _state->game(this);
    }
}

void	Core::initState() {
    this->_state = new SplashScreen();
}

void	Core::splash(){
    this->_state->splash(this);
}

void	Core::menu() {
    this->_state->menu(this);
}

void	Core::options() {
    this->_state->options(this);
}

void	Core::game() {
    this->_state->game(this);
}
