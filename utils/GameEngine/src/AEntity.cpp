//
// Created by sentrance on 10/01/18.
//

#include "../include/AEntity.hpp"

void UgandaEngine::AEntity::addComponent(const UgandaEngine::AComponent &component) {
    _Components.push_back(component);
}