//
// Created by Samy on 22/01/2018.
//

#ifndef R_TYPE_CONNEXIONSTATE_HPP
#define R_TYPE_CONNEXIONSTATE_HPP

#include "IState.hpp"
#include "Core.hpp"

class ConnexionState : public IState {
	std::shared_ptr<ILib> lib;
	CoreInfo &_info;
public:
	ConnexionState(CoreInfo &info) : _info(info) {}
	virtual ~ConnexionState() = default;
	virtual void splash(std::shared_ptr<IState> &state);
	virtual void menu(std::shared_ptr<IState> &state);
	virtual void options(std::shared_ptr<IState> &state);
	virtual void game(std::shared_ptr<IState> &state);
	virtual void connexion(std::shared_ptr<IState> &state);
	virtual void lobby(std::shared_ptr<IState> &state);

	virtual int exec();
	virtual void init(std::shared_ptr<ILib> &lib);
};

#endif //R_TYPE_CONNEXIONSTATE_HPP
