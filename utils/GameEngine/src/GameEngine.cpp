//
// Created by sentrance on 10/01/18.
//

#include "../include/GameEngine.hpp"

void UgandaEngine::GameEngine::start() {
    sf::Clock clock;

    while (_Window.isOpen()) {
        //Saves elapsed time into dt then restart the clock
        sf::Time dt = clock.restart();
        float deltaSeconds = dt.asSeconds();

        update(deltaSeconds);
    }
}

UgandaEngine::GameEngine::GameEngine() {
    // Get the screen resolution and create an SFML window and View
    sf::Vector2f resolution;

    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    _Window.create(sf::VideoMode(static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)),
                    "Simple Game Engine", sf::Style::Fullscreen);

    //Here add a background and entities
}

void UgandaEngine::GameEngine::update(float deltaTime) {
    //Call every update entities event
    for (AEntity e : _Entities) {
        e.update(deltaTime);
    }
}
