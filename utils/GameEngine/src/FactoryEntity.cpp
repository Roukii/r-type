//
// Created by youssef on 14/01/18.
//


#include "../include/FactoryEntity.hpp"

namespace UgandaEngine {
    namespace Factory {

        FactoryEntity::FactoryEntity(const std::map<std::string, std::vector<std::string>> &entity,
                                     const std::map<std::string, std::function> &action)
        {
            _entity = entity;
            _action = action;
        }

        std::shared_ptr<Entity> FactoryEntity::create(const std::string &name) {
            if (_entity.find(name) == _entity.end()) {
                std::cout << "error name not found" << std::endl;
                return NULL;
            }
            std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();
            for (auto e : _entity[name]) {
                newEntity->_Components.insert(std::pair(e, _action[e]));
            }
            return newEntity;
        }
    }
}