//
// Created by Samy on 10/01/2018.
//

#include <SplashState.hpp>

Core::Core()
{

	_engine = std::make_shared<UgandaEngine::AGameEngine>();


	std::map<std::string, std::vector<std::string>> entities;
	std::map<std::string, std::function<void()>> functions;
	std::shared_ptr<EntityFunc> func = std::make_shared<EntityFunc>();

	std::vector<UgandaEngine::Entity> entities1;

	std::vector<std::string> componentNames;
	componentNames.emplace_back("shoot");

	entities["Ship"] = componentNames;
	entities["Ennemy"] = componentNames;
	entities["Shoot"] = componentNames;
    std::function<void()> shoot = func->shoot;
    functions["shoot"] = shoot;

	_engine->init(componentNames, entities, functions);

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
		if (elapsed_time.count() / 10000000 >= waitTime)
			wait = false;
		if (!_info.getMessageQueue().isEmpty())
		{
			RTypeProtocol::code msgCode = (RTypeProtocol::code)_info.getMessageQueue().peekMessage()._msg.get()->_header._code;
			_info.getMessageQueue().pop();
			return msgCode == RTypeProtocol::OK;
		}
	}
	std::cout << "can't connect" << std::endl;
	_info.getSocket()->shutdown();
	return false;
}
