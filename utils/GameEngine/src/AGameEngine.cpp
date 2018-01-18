//
// Created by sentrance on 10/01/18.
//

#include "../include/AGameEngine.hpp"

void UgandaEngine::AGameEngine::start() {
    while (isAlive()) {
        //Check if a key was input
        gameLoop();
    }
}

UgandaEngine::AGameEngine::AGameEngine() {
        // Get the screen resolution and create an SFML window and View
        //drawWindow();
}

//void UgandaEngine::AGameEngine::update(float deltaTime, KeyInput keyInput) {
//    //Call every update entities event
//    for (AEntity e : _Entities) {
//        e.update(deltaTime, keyInput);
//    }
//}

void UgandaEngine::AGameEngine::addEntity(const UgandaEngine::AEntity &newEntity) {
//    _Entities.push_back(newEntity);
}