//
// Created by sentrance on 10/01/18.
//

#include "../include/AGameEngine.hpp"

void AUgandaEngine::AGameEngine::start() {
    //TODO: problème ici pour la cond !
    while (isWindowOpen()) {
        //Check if a key was input
        gameLoop();
    }
}

AUgandaEngine::AGameEngine::AGameEngine() {
        // Get the screen resolution and create an SFML window and View
        drawWindow();
}

void AUgandaEngine::AGameEngine::update(float deltaTime, KeyInput keyInput) {
    //Call every update entities event
    for (AEntity e : _Entities) {
        e.update(deltaTime, keyInput);
    }
}

void AUgandaEngine::AGameEngine::addEntity(const AUgandaEngine::AEntity &newEntity) {
    _Entities.push_back(newEntity);
}