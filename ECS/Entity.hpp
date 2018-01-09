//
// Created by Alexandre on 1/9/2018.
//

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include <map>
#include <string>

#include "Component.hpp"

class Entity
{
public:
    Entity(const std::string &name) : _name(name) {}
    ~Entity() = default;

    void addComponent(Component &c) { _component["example"];}
private:
    oonst std::string &_name;
    std::map<int, Component &> _component;
};

#endif //RTYPE_ENTITY_HPP
