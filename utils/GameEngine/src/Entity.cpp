//
// Created by sentrance on 10/01/18.
//

#include "../include/Entity.hpp"

void UgandaEngine::entity::Entity::addComponent(std::type_index type, std::shared_ptr<UgandaEngine::AComponent> component) {
    _components[type] = component;
}