//
// Created by youssef on 14/01/18.
//


#include "../include/FactoryEntity.hpp"

namespace UgandaEngine {
    namespace Factory {

        FactoryEntity::FactoryEntity(const std::map<std::string, std::vector<std::string>> &entity,
                                     const std::map<std::string, std::function<void()>> &action)
        {
            _entity = entity;
            _action = action;
        }

        std::shared_ptr<entity::Entity> FactoryEntity::create(const std::string &name) {
            if (_entity.find(name) == _entity.end()) {
                std::cout << "error name not found" << std::endl;
                return NULL;
            }
            std::shared_ptr<entity::Entity> newEntity = std::make_shared<entity::Entity>();
            for (auto e : _entity[name]) {
                newEntity->_funcComp.insert(std::pair<std::string, std::function<void()>>(e, _action[e]));
            }
            // LibGraĥique => pour récupérer toutes les données lié à l'affichage
            // Initialiser par défaut de la vitesse / direction / position
            return newEntity;
        }
    }
}