//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_ISTATE_HPP
#define R_TYPE_ISTATE_HPP

class Core;

class IState {
public:
    virtual void splash(Core *core) = 0;
    virtual void menu(Core *core) = 0;
    virtual void options(Core *core) = 0;
    virtual void game(Core *core) = 0;

    virtual int exec() = 0;
    virtual void init() = 0;
    template<typename T>
    IState *screen()
    {
        return new T();
    }
};

#endif //R_TYPE_ISTATE_HPP
