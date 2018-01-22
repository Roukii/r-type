//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_CORE_HPP
#define R_TYPE_CORE_HPP

#include "../../State/include/IState.hpp"
#include "../../State/include/MenuState.hpp"
#include "../../../utils/GameEngine/include/AGameEngine.hpp"

class Core {
    std::shared_ptr<IState>	_state;
	std::shared_ptr<UgandaEngine::AGameEngine> _engine;
public:
	Core();
	~Core() = default;

	void		start();

	//States
	void		splash();
	void		menu();
	void		options();
	void		game();

	//Setters and getters
	void		setState(std::shared_ptr<IState> newState) { this->_state = std::move(newState); }
};


#endif //R_TYPE_CORE_HPP
