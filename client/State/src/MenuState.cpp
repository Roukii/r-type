//
// Created by Samy on 10/01/2018.
//

#include "../include/MenuState.hpp"

#include "../include/SplashState.hpp"
#include "../include/GameState.hpp"
#include "../include/OptionsState.hpp"

void	MenuState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>();
}

void	MenuState::menu(std::shared_ptr<IState> &state) {
}

void	MenuState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>();
}

void	MenuState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>();
}

int    MenuState::exec(std::shared_ptr<sf::RenderWindow> win) {
    // Process events
    sf::Event event;
    int ret;
    while (win->pollEvent(event)) {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            win->close();
        if ((ret = m.handleKeys(event)) != 1)
            return ret;
    }
    // Clear screen
    win->clear();

    // Update the window
    win->draw(m.getSprite()[0]);
    win->draw(m.getSprite()[1]);
    win->draw(m.getText()[0]);
    win->draw(m.getText()[1]);
    win->draw(m.getText()[2]);
    win->draw(m.getText()[3]);
    win->display();
    return -1;
}

void   MenuState::init() {
    m = Menu();
}