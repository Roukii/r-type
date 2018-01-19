//
// Created by sentrance on 10/01/18.
//

#include "../include/Entity.hpp"

void UgandaEngine::Entity::addComponent(const UgandaEngine::AComponent &component) {
    _Components.push_back(component);
}
