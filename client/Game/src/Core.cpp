//
// Created by Samy on 10/01/2018.
//


#include <TestComponent.hpp>
#include <SplashState.hpp>

Core::Core() : _state(std::make_shared<SplashState>())
{
    //Game Engine => lib Graphique // Game Engine + LibGraphique => Entity
    // TODO : ALexis stp rempli les 2 map, ainsi que le petit vector qui les accompagnent
	// Demander des explications pour faire ça ^^

    _engine = std::make_shared<UgandaEngine::AGameEngine>();

    // TODO : Init all the functions needed for the Entities action here and in EntityFunc.cpp/hpp

    //Definition des entities et des fonctions associées
    std::map<std::string, std::vector<std::string>> entities;
	std::map<std::string, std::function<void(RTypeProtocol::Message&)>> functions;
    std::shared_ptr<EntityFunc> func = std::make_shared<EntityFunc>();

    std::vector<UgandaEngine::entity::Entity> entities1;

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
    std::function<void(RTypeProtocol::Message&)> left = func->move_left;
	//std::function<void(RTypeProtocol::Message&)> left = EntityFunc::move_left;
    functions["moveLeft"] = left;
    std::function<void(RTypeProtocol::Message&)> right = func->move_right;
    functions["moveRight"] = right;
    std::function<void(RTypeProtocol::Message&)> down = func->move_down;
    functions["moveDown"] = down;
    std::function<void(RTypeProtocol::Message&)> up = func->move_up;
    functions["moveUp"] = up;
    std::function<void(RTypeProtocol::Message&)> shoot = func->shoot;
    functions["shoot"] = shoot;

    //Confirmation
    _engine->init(componentNames, entities, functions);


    //Exemple de création d'entity.
    UgandaEngine::entity::Entity entity;

    //On créer les component
    std::shared_ptr<UgandaEngine::TestComponent> component = std::make_shared<UgandaEngine::TestComponent>();
    component->setPhrase("LOL");

    //On ajoute les component
    entity.addComponent(std::type_index(typeid(UgandaEngine::TestComponent)), component);

    //Pour récupérer depuis une entity un component:
    std::weak_ptr<UgandaEngine::TestComponent> getter = entity.get<UgandaEngine::TestComponent>();
    if (!getter.expired())
        std::cout << getter.lock()->getPhrase() << std::endl;
    else
        std::cout << "Ce component n'existe pas!" << std::endl;
}

void    Core::start() {
    int ret = 0;
    splash();

    //TODO: zone de test!!!
    {
        std::shared_ptr<UgandaEngine::entity::Entity> ship = std::move(
                _engine->_factory->create("Ship", _engine->_libGraph));
	    RTypeProtocol::Message msg;
        ship->_funcComp["shoot"](msg);

        //Test
        UgandaEngine::TestComponent testComponent;
        UgandaEngine::entity::Entity *entity = _engine->createEnWithLua("../assets/entities.lua", "Test");
        std::weak_ptr<UgandaEngine::TestComponent> getter = entity->get<UgandaEngine::TestComponent>();
        if (!getter.expired())
            std::cout << getter.lock().get()->getPhrase() << std::endl;
        else
            std::cout << "error "<< std::endl;
    }

    while (ret != -2) {
        ret =  _state->exec();
        if (ret == 0)
            splash();
        else if (ret == 1)
            menu();
        else if (ret == 2)
            options();
        else if (ret == 3)
            game();
        else if (ret == 4)
            connexion();
        else if (ret == 5)
            lobby();
    }
}

void	Core::splash(){
    this->_state->splash(_state);
    this->_state->init(_engine->_libGraph, _info);
}

void	Core::menu() {
    this->_state->menu(_state);
    this->_state->init(_engine->_libGraph, _info);
}

void	Core::options() {
    this->_state->options(_state);
    this->_state->init(_engine->_libGraph, _info);
}

void	Core::game() {
    this->_state->game(_state);
    this->_state->init(_engine->_libGraph, _info);
}

void	Core::connexion() {
    this->_state->connexion(_state);
    this->_state->init(_engine->_libGraph, _info);
}

void	Core::lobby() {
    this->_state->lobby(_state);
    this->_state->init(_engine->_libGraph, _info);
}
