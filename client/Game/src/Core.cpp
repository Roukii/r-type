//
// Created by Samy on 10/01/2018.
//

#include <iostream>
#include "Core.hpp"
#include "../../State/include/MenuState.hpp"


Core::Core() : _state(std::make_shared<MenuState>()), _ugl(std::make_shared<UGL>())
{
    //Game Engine => lib Graphique // Game Engine + LibGraphique => Entity

}

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
    int ret = 0;
    while (_ugl->getWindow().isOpen() && ret != -2) {
        ret =  _state->exec(_ugl->getWindow());
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
