//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_ISTATE_HPP
#define R_TYPE_ISTATE_HPP

#include <memory>
#include "ILib.hpp"
#include <AGameEngine.hpp>
#include "CoreInfo.hpp"

class IState {
public:
    virtual void changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine) = 0;

    virtual int exec() = 0;
    virtual void init() = 0;
};

#endif //R_TYPE_ISTATE_HPP
