//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_OPTIONSSCREEN_HPP
#define R_TYPE_OPTIONSSCREEN_HPP

#include <KeyHandler.hpp>
#include "IState.hpp"
#include "Core.hpp"

class OptionsState : public IState {
	CoreInfo &_info;
	std::shared_ptr<UgandaEngine::AGameEngine> engine;
	std::shared_ptr<key::KeyHandler> myKeys;
public:
    OptionsState(CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> eng) : _info(info), engine(eng) {};
    virtual ~OptionsState() = default;
	virtual void changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine);

    virtual int exec();
    virtual void init();
};

#endif //R_TYPE_OPTIONSSCREEN_HPP
