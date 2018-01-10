//
// Created by Samy on 10/01/2018.
//

#include <iostream>
#include "../include/Core.hpp"
#include "../include/SplashScreen.hpp"

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
    this->_state = std::make_shared<SplashScreen>();
    while (1) {
        _state->exec();
        std::string lol;
        getline(std::cin, lol);
        if (lol == "splash")
            splash();
        else if (lol == "menu")
            menu();
        else if (lol == "options")
            options();
        else if (lol == "game")
            game();
    }
}

void	Core::splash(){
    this->_state->splash(_state);
}

void	Core::menu() {
    this->_state->menu(_state);
}

void	Core::options() {
    this->_state->options(_state);
}

void	Core::game() {
    this->_state->game(_state);
}
