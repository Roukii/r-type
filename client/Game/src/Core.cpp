//
// Created by Samy on 10/01/2018.
//

#include <SplashState.hpp>

Core::Core()
{
	//Game Engine => lib Graphique // Game Engine + LibGraphique => Entity
	// Demander des explications pour faire ça ^^

	_engine = std::make_shared<UgandaEngine::AGameEngine>();


	//SHIP
	//Definition des entities et des fonctions associées
	std::map<std::string, std::vector<std::string>> entities;
	std::map<std::string, std::function<void()>> functions;
	std::shared_ptr<EntityFunc> func = std::make_shared<EntityFunc>();

	std::vector<UgandaEngine::Entity> entities1;

	//On liste les components par nom
	std::vector<std::string> componentNames;
//	componentNames.emplace_back("moveLeft");
//	componentNames.emplace_back("moveRight");
//	componentNames.emplace_back("moveDown");
//	componentNames.emplace_back("moveUp");
	componentNames.emplace_back("shoot");

	//On associe à ship les components par nom.
	entities["Ship"] = componentNames;
	entities["Ennemy"] = componentNames;

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
    std::function<void()> shoot = func->shoot;
    functions["shoot"] = shoot;

	//Confirmation
	_engine->init(componentNames, entities, functions);

	//TODO: Remplir fonction associés aux ennemis si necessaire
	//ENEMY
	entities.clear();
	functions.clear();
	func.reset();

	_state = std::make_shared<SplashState>(_info, _engine);


}

void    Core::start() {
	int ret = 0;

	this->_state->changeScreen(_state, "SPLASH",_info, _engine);

	while (ret != -2) {
		ret =  _state->exec();
		if (ret == 0) {
			this->_state->changeScreen(_state, "SPLASH",_info, _engine);
			this->_state->init();
		}
		else if (ret == 1) {
			if (_engine->_libGraph->getIpAdress() == ""
					|| _engine->_libGraph->getIpAdress().size() > 14
					|| _engine->_libGraph->getPort() == "")
			{
				this->_state->changeScreen(_state, "CONNEXION", _info, _engine);
				this->_state->init();
			}
			else {
				if (!_info.isRunning())
					_info.startSocket(_engine->_libGraph->getIpAdress(),
									  std::atoi(_engine->_libGraph->getPort().c_str()));
				if (checkServer()) {
					this->_state->changeScreen(_state, "MENU", _info, _engine);
					this->_state->init();
				} else {
					_info.shutdownSocket();
					this->_state->changeScreen(_state, "CONNEXION", _info, _engine);
					this->_state->init();
				}
			}
		}
		else if (ret == 2) {
			this->_state->changeScreen(_state, "OPTIONS",_info, _engine);
			this->_state->init();
		}
		else if (ret == 3) {
			std::cout << "return game" << std::endl;
			this->_state->changeScreen(_state, "GAME", _info, _engine);
			this->_state->init();
		}
		else if (ret == 4) {
			this->_state->changeScreen(_state, "CONNEXION",_info, _engine);
			this->_state->init();
		}
		else if (ret == 5) {
			this->_state->changeScreen(_state, "LOBBY",_info, _engine);
			this->_state->init();
		}
		else if (ret == 6) {
			CoreInfo::RoomInfo choosenRoom =_info.getRooms()[_engine->_libGraph->getJoin()];
			if (choosenRoom.inGame)
			{
				this->_state->changeScreen(_state, "LOBBY",_info, _engine);
				this->_state->init();
			}
			else {
				std::cout << "LE ROUX A FAIL!" << std::endl;
				this->_state->changeScreen(_state, "READY", _info, _engine);
				this->_state->init();
			}
		}
	}
	_info.shutdownSocket();
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
