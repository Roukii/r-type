//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_CORE_HPP
#define R_TYPE_CORE_HPP

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

	//States
	void		splash();
	void		menu();
	void		options();
	void		game();
	void		connexion();
	void		lobby();

	//Setters and getters
	void		setState(std::shared_ptr<IState> newState) { this->_state = std::move(newState); }

private:
    bool checkServer();
};


#endif //R_TYPE_CORE_HPP
