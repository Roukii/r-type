//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_OPTIONSSCREEN_HPP
#define R_TYPE_OPTIONSSCREEN_HPP

#include "IState.hpp"
#include "Core.hpp"

class OptionsState : public IState {
public:
    OptionsState(){};
    virtual ~OptionsState(){};
    virtual void splash(std::shared_ptr<IState> &state);
    virtual void menu(std::shared_ptr<IState> &state);
    virtual void options(std::shared_ptr<IState> &state);
    virtual void game(std::shared_ptr<IState> &state);

    virtual int exec(sf::RenderWindow &win);
    virtual void init();
};

#endif //R_TYPE_OPTIONSSCREEN_HPP
