//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_ISTATE_HPP
#define R_TYPE_ISTATE_HPP

#include <memory>

#include "ILib.hpp"

class IState {
public:
    virtual void splash(std::shared_ptr<IState> &state) = 0;
    virtual void menu(std::shared_ptr<IState> &state) = 0;
    virtual void options(std::shared_ptr<IState> &state) = 0;
    virtual void game(std::shared_ptr<IState> &state) = 0;
    virtual void connexion(std::shared_ptr<IState> &state) = 0;
    virtual void lobby(std::shared_ptr<IState> &state) = 0;

    virtual int exec() = 0;
    virtual void init(std::shared_ptr<ILib> &lib) = 0;
    template<typename T>
    IState* screen() {
        return new T();
    }
};

#endif //R_TYPE_ISTATE_HPP
