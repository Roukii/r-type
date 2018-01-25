//
// Created by Samy on 10/01/2018.
//


#include <TestComponent.hpp>
#include "Core.hpp"

Core::Core() : _state(std::make_shared<MenuState>())
{
    //Game Engine => lib Graphique // Game Engine + LibGraphique => Entity
    // TODO : ALexis stp rempli les 2 map, ainsi que le petit vector qui les accompagnent
	// Demander des explications pour faire ça ^^

    _engine = std::make_shared<UgandaEngine::AGameEngine>();

    // TODO : Init all the functions needed for the Entities action here and in EntityFunc.cpp/hpp

    //Definition des entities et des fonctions associées
    std::map<std::string, std::vector<std::string>> entities;
	std::map<std::string, std::function<void()>> functions;
    std::shared_ptr<EntityFunc> func = std::make_shared<EntityFunc>();

    //On liste les components par nom
    std::vector<std::string> componentNames;
    componentNames.emplace_back("moveLeft");
    componentNames.emplace_back("moveRight");
    componentNames.emplace_back("moveDown");
    componentNames.emplace_back("moveUp");
    componentNames.emplace_back("shoot");

    //On associe à ship les components par nom.
    entities["Ship"] = componentNames;

    //On associe à chaque nom de component une fonction
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

    //Confirmation
    _engine->init(componentNames, entities, functions);
}

void    Core::start() {
    int ret = 0;
    menu();

    // TODO : Test your Entity creation here

    std::shared_ptr<UgandaEngine::entity::Entity> ship = std::move(_engine->_factory->create("Ship", _engine->_libGraph));
    ship->_funcComp["shoot"]();

    //Test
    UgandaEngine::entity::Entity *entity = _engine->createEnWithLua("../assets/ghost.lua", "ghost");
    std::weak_ptr<UgandaEngine::TestComponent> getter = entity->get<UgandaEngine::TestComponent>();
    std::cout << getter.lock().get()->getPhrase() << std::endl;

    while (_engine->_libGraph->getWindow()->isOpen() && ret != -2) {
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
    this->_state->init(_engine->_libGraph);
}

void	Core::menu() {
    this->_state->menu(_state);
    this->_state->init(_engine->_libGraph);
}

void	Core::options() {
    this->_state->options(_state);
    this->_state->init(_engine->_libGraph);
}

void	Core::game() {
    this->_state->game(_state);
    this->_state->init(_engine->_libGraph);
}

void	Core::connexion() {
    this->_state->connexion(_state);
    this->_state->init(_engine->_libGraph);
}

void	Core::lobby() {
    this->_state->lobby(_state);
    this->_state->init(_engine->_libGraph);
}
