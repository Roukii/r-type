//
// Created by youssef on 14/01/18.
//


#include "FactoryEntity.hpp"

namespace UgandaEngine {
    namespace Factory {

        FactoryEntity::FactoryEntity(const std::map<std::string, std::vector<std::string>> &entity,
                                     const std::map<std::string, std::function<void()>> &action)
        {
            _entity = entity;
            _action = action;

        }

        Entity *FactoryEntity::create(const RTypeProtocol::types &type, std::shared_ptr<ILib> lib) {
            Entity *newEntity;
            std::string name;
            if (type == RTypeProtocol::types::SHIP)
                name = "Ship";
            if (type == RTypeProtocol::types::ENNEMY)
                name = "Ennemy";

            if (_entity.find(name) == _entity.end()) {
                std::cout << "error name not found" << std::endl;
                return newEntity;
            }
            newEntity = new Entity();
            for (auto e : _entity[name]) {
                newEntity->_funcComp.insert(std::pair<std::string, std::function<void()>>(e, _action[e]));
            }
            newEntity->name = name;

            newEntity->_myGraph = lib->factoryData(name);
            newEntity->_posX = 10;
            newEntity->_posY = 10;
            newEntity->_speedX = 0;
            newEntity->_speedY = 0;
            return newEntity;
        }
    }
}