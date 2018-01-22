//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_MENUSCREEN_HPP
#define R_TYPE_MENUSCREEN_HPP

#include "IState.hpp"
#include "Core.hpp"

class MenuState : public IState {
    int selected = 0;
    std::shared_ptr<ILib> lib;
public:
    MenuState() = default;
    virtual ~MenuState() = default;
    virtual void splash(std::shared_ptr<IState> &state);
    virtual void menu(std::shared_ptr<IState> &state);
    virtual void options(std::shared_ptr<IState> &state);
    virtual void game(std::shared_ptr<IState> &state);
    virtual void connexion(std::shared_ptr<IState> &state);
    virtual void lobby(std::shared_ptr<IState> &state);

    virtual int exec();
    virtual void init(std::shared_ptr<ILib> &lib);

    void    moveUp();
    int handleKeys(const sf::Event&e);
    void    moveDown();

};

#endif //R_TYPE_MENUSCREEN_HPP
