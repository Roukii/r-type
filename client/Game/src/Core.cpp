//
// Created by Samy on 10/01/2018.
//


#include <TestComponent.hpp>
#include <SplashState.hpp>

Core::Core() : _state(std::make_shared<SplashState>(_info))
{
	//Game Engine => lib Graphique // Game Engine + LibGraphique => Entity
	// TODO : ALexis stp rempli les 2 map, ainsi que le petit vector qui les accompagnent
	// Demander des explications pour faire ça ^^

	_engine = std::make_shared<UgandaEngine::AGameEngine>();

	// TODO : Init all the functions needed for the Entities action here and in EntityFunc.cpp/hpp

	//SHIP
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
//    std::function<void(RTypeProtocol::Message&)> left = func->move_left;
//	//std::function<void(RTypeProtocol::Message&)> left = EntityFunc::move_left;
//    functions["moveLeft"] = left;
//    std::function<void(RTypeProtocol::Message&)> right = func->move_right;
//    functions["moveRight"] = right;
//    std::function<void(RTypeProtocol::Message&)> down = func->move_down;
//    functions["moveDown"] = down;
//    std::function<void(RTypeProtocol::Message&)> up = func->move_up;
//    functions["moveUp"] = up;
//    std::function<void(RTypeProtocol::Message&)> shoot = func->shoot;
//    functions["shoot"] = shoot;

	//Confirmation
	_engine->init(componentNames, entities, functions);

	//TODO: Remplir fonction associés aux ennemis si necessaire
	//ENEMY
	entities.clear();
	functions.clear();
	func.reset();




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

	while (ret != -2) {
		ret =  _state->exec();
		if (ret == 0)
			splash();
		else if (ret == 1) {
			if (!_info.isRunning())
				_info.startSocket(_engine->_libGraph->getIpAdress(), std::atoi(_engine->_libGraph->getPort().c_str()));
			if (checkServer())
			{
				menu();
			}
			else {
				_info.shutdownSocket();
				connexion();
			}
		}
		else if (ret == 2)
			options();
		else if (ret == 3)
			game();
		else if (ret == 4)
			connexion();
		else if (ret == 5)
			lobby();
	}
	_info.shutdownSocket();
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

bool Core::checkServer() {
	std::chrono::system_clock::time_point clock_start = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point clock_elapsed = std::chrono::system_clock::now();
	std::chrono::system_clock::duration elapsed_time;

	bool wait = true;
	long waitTime = 2;

	RTypeProtocol::Message sendOk;
	sendOk._msg.get()->_header._code = RTypeProtocol::OK;

	_info.getSocket().get()->SendToServer(sendOk);

	while (wait)
	{
		clock_elapsed = std::chrono::system_clock::now();
		elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(clock_elapsed - clock_start);
		if (elapsed_time.count() / 1000000000 >= waitTime)
			wait = false;
		if (!_info.getMessageQueue().isEmpty())
		{
			RTypeProtocol::code msgCode = (RTypeProtocol::code)_info.getMessageQueue().peekMessage()._msg.get()->_header._code;
			_info.getMessageQueue().pop();
			return msgCode == RTypeProtocol::OK;
		}
	}
	std::cout << "can't connect" << std::endl;
	return false;
}
