//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_CORE_HPP
#define R_TYPE_CORE_HPP


#include "IState.hpp"

class Core {
    IState			*_state;
public:
	Core(){};
	~Core(){};

	//Initialisation
//    void		initLib(int x, int y);
	void		initState();
	void        start();

	//States
    void        splash();
	void		menu();
	void		options();
	void		game();

	//Setters and getters
	void        setState(IState *newState) { this->_state = newState; };
};


#endif //R_TYPE_CORE_HPP
