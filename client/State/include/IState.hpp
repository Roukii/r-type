//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_ISTATE_HPP
#define R_TYPE_ISTATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class IState {
public:
    virtual void splash(std::shared_ptr<IState> &state) = 0;
    virtual void menu(std::shared_ptr<IState> &state) = 0;
    virtual void options(std::shared_ptr<IState> &state) = 0;
    virtual void game(std::shared_ptr<IState> &state) = 0;

    virtual int exec(std::shared_ptr<sf::RenderWindow> win) = 0;
    virtual void init() = 0;
    template<typename T>
    IState* screen() {
        return new T();
    }
};

#endif //R_TYPE_ISTATE_HPP
