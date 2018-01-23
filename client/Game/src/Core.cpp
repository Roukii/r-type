//
// Created by Samy on 10/01/2018.
//


#include "Core.hpp"

Core::Core() : _state(std::make_shared<MenuState>())
{
    //Game Engine => lib Graphique // Game Engine + LibGraphique => Entity
    // TODO : ALexis stp rempli les 2 map, ainsi que le petit vector qui les accompagnent
	// Demander des explications pour faire ça ^^

    _engine = std::make_shared<UgandaEngine::AGameEngine>();

    // TODO : Init all the functions needed for the Entities action here and in EntityFunc.cpp/hpp
    std::map<std::string, std::vector<std::string>>		entities;
	std::map<std::string, std::function<void()>>		functions;
    std::shared_ptr<EntityFunc> func = std::make_shared<EntityFunc>();
    std::vector<std::string> componentNames;
    componentNames.push_back("moveLeft");
    componentNames.push_back("moveRight");
    componentNames.push_back("moveDown");
    componentNames.push_back("moveUp");
    componentNames.push_back("shoot");
    entities["Ship"] = componentNames;
    std::function<void()> left = func->move_left;
    functions["moveLeft"] = left;
    std::function<void()> right = func->move_right;
    functions["moveRight"] = right;
    std::function<void()> down = func->move_down;
    functions["moveDown"] = down;
    std::function<void()> up = func->move_up;
    functions["moveUp"] = up;
    std::function<void()> shoot = func->shoot;
    functions["shoot"] = shoot;
    _engine->init(componentNames, entities, functions);
}

void    Core::start() {
    int ret = 0;
    menu();

    // TODO : Test your Entity creation here

    std::shared_ptr<UgandaEngine::entity::Entity> ship = _engine->factory->create("Ship", _engine->libGraph);
    ship->_funcComp["shoot"]();

    while (_engine->libGraph->getWindow()->isOpen() && ret != -2) {
        ret =  _state->exec();
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
    this->_state->init(_engine->libGraph);
}

void	Core::menu() {
    this->_state->menu(_state);
    this->_state->init(_engine->libGraph);
}

void	Core::options() {
    this->_state->options(_state);
    this->_state->init(_engine->libGraph);
}

void	Core::game() {
    this->_state->game(_state);
    this->_state->init(_engine->libGraph);
}

void	Core::connexion() {
    this->_state->connexion(_state);
    this->_state->init(_engine->libGraph);
}

void	Core::lobby() {
    this->_state->lobby(_state);
    this->_state->init(_engine->libGraph);
}
