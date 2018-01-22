//
// Created by Samy on 10/01/2018.
//

#include <iostream>
#include "Core.hpp"
#include "../../State/include/MenuState.hpp"
#include "../../../utils/GameEngine/include/AGameEngine.hpp"


Core::Core() : _state(std::make_shared<MenuState>())
{
    //Game Engine => lib Graphique // Game Engine + LibGraphique => Entity
    // TODO : ALexis stp rempli les 2 map, ainsi que le petit vector qui les accompagnent
}

void    Core::start() {
    int ret = 0;
    auto win = UgandaEngine::g_engine.libGraph->getWindow();
    while (win->isOpen() && ret != -2) {
        ret =  _state->exec(win);
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
