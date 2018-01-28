//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_OPTIONSSCREEN_HPP
#define R_TYPE_OPTIONSSCREEN_HPP

#include "IState.hpp"
#include "Core.hpp"

class OptionsState : public IState {
    std::shared_ptr<ILib> lib;
	CoreInfo &_info;
	std::shared_ptr<UgandaEngine::AGameEngine> engine;
public:
    OptionsState(CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> eng) : _info(info), engine(eng) {};
    virtual ~OptionsState() = default;
    virtual void splash(std::shared_ptr<IState> &state);
    virtual void menu(std::shared_ptr<IState> &state);
    virtual void options(std::shared_ptr<IState> &state);
    virtual void game(std::shared_ptr<IState> &state);
    virtual void connexion(std::shared_ptr<IState> &state);
    virtual void lobby(std::shared_ptr<IState> &state);

    virtual int exec();
    virtual void init(std::shared_ptr<ILib> &lib);
};

#endif //R_TYPE_OPTIONSSCREEN_HPP
