//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_OPTIONSSCREEN_HPP
#define R_TYPE_OPTIONSSCREEN_HPP

#include "IState.hpp"
#include "Core.hpp"

class OptionsScreen : public IState {
public:
    OptionsScreen(){};
    virtual ~OptionsScreen(){};
    virtual void splash(Core *core);
    virtual void menu(Core *core);
    virtual void options(Core *core);
    virtual void game(Core *core);

    virtual int exec();
    virtual void init();
};

#endif //R_TYPE_OPTIONSSCREEN_HPP
