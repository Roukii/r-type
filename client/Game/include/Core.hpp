//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_CORE_HPP
#define R_TYPE_CORE_HPP

#ifdef _WIN32
#define _WIN32_WINNT 0x0501
#endif

#include "IState.hpp"
#include "MenuState.hpp"
#include "AGameEngine.hpp"
#include "EntityFunc.hpp"

class Core {
    std::shared_ptr<IState>	_state;
	std::shared_ptr<UgandaEngine::AGameEngine> _engine;
	CoreInfo _info;

public:
	Core();
	~Core() = default;

	void		start();


	//Setters and getters
	void		setState(std::shared_ptr<IState> newState) {}

private:
    bool checkServer();
};


#endif //R_TYPE_CORE_HPP
