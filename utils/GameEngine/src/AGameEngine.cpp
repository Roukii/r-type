//
// Created by sentrance on 10/01/18.
//


#include "../include/AGameEngine.hpp"

//TODO: bugfix de compilation
//void UgandaEngine::AGameEngine::start() {
//    while (isAlive()) {
//        //Check if a key was input
//        gameLoop();
//    }
//}
//
UgandaEngine::AGameEngine::AGameEngine() {
        // Get the screen resolution and create an SFML window and View
        //drawWindow();
}
//
////void UgandaEngine::AGameEngine::update(float deltaTime, KeyInput keyInput) {
////    //Call every update entities event
////    for (Entity e : _Entities) {
////        e.update(deltaTime, keyInput);
////    }
////}
//
//void UgandaEngine::AGameEngine::addEntity(const UgandaEngine::Entity &newEntity) {
//    _Entities.push_back(newEntity);
//}
//
void UgandaEngine::AGameEngine::init(const std::vector<std::string> &component,
                                     const std::map<std::string, std::vector<std::string>> &entity,
                                     const std::map<std::string, std::function<void()>> &action)
{
    //TODO LibGraph à implémenter
    factory = std::make_shared<Factory::FactoryEntity>(entity, action);
}
