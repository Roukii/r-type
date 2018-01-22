//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_CORE_HPP
#define R_TYPE_CORE_HPP

#include <memory>
#include <utility>
#include "../../Lib/include/UGL.hpp"
#include "../../State/include/IState.hpp"

class Core {
    std::shared_ptr<IState>	_state;
public:
	Core();
	~Core() = default;

	//Initialisation
//    void		initLib(int x, int y);
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
