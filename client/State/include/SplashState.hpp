//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_SPLASH_HPP
#define R_TYPE_SPLASH_HPP

#include "IState.hpp"
#include "Core.hpp"

class SplashState : public IState {
    std::shared_ptr<ILib> lib;
	std::shared_ptr<CoreInfo> info;
public:
    SplashState() = default;
    virtual ~SplashState() = default;
    virtual void splash(std::shared_ptr<IState> &state);
    virtual void menu(std::shared_ptr<IState> &state);
    virtual void options(std::shared_ptr<IState> &state);
    virtual void game(std::shared_ptr<IState> &state);
    virtual void connexion(std::shared_ptr<IState> &state);
    virtual void lobby(std::shared_ptr<IState> &state);

    virtual int exec();
    virtual void init(std::shared_ptr<ILib> &lib, std::shared_ptr<CoreInfo> &info);
};

#endif //R_TYPE_SPLASH_HPP
