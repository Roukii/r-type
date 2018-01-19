//
// Created by Samy on 10/01/2018.
//

#include <iostream>
#include "../include/Core.hpp"
#include "../include/SplashState.hpp"
#include "../include/MenuState.hpp"

Core::Core()
        : _state(std::make_shared<MenuState>()) {}

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
    //this->_state = std::make_shared<MenuState>();
    sf::RenderWindow	win(sf::VideoMode(1920, 1080), "R-Type");
    while (1) {
      int ret =  _state->exec(win);
        std::cout << ret << std::endl;
        if (ret == 0)
            splash();
        else if (ret == 1)
            menu();
        else if (ret == 2)
            options();
        else if (ret == 3)
            game();
    }
}

void	Core::splash(){
    this->_state->splash(_state);
    this->_state->init();
}

void	Core::menu() {
    this->_state->menu(_state);
    this->_state->init();
}

void	Core::options() {
    this->_state->options(_state);
    this->_state->init();
}

void	Core::game() {
    this->_state->game(_state);
    this->_state->init();
}
