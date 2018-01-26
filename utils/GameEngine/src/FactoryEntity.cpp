//
// Created by youssef on 14/01/18.
//


#include "FactoryEntity.hpp"

namespace UgandaEngine {
    namespace Factory {

        FactoryEntity::FactoryEntity(const std::map<std::string, std::vector<std::string>> &entity,
                                     const std::map<std::string, std::function<void(RTypeProtocol::Message&)>> &action)
        {
            _entity = entity;
            _action = action;

        }

        std::shared_ptr<entity::Entity> FactoryEntity::create(const std::string &name, std::shared_ptr<ILib> lib) {
            std::shared_ptr<entity::Entity> newEntity;
            if (_entity.find(name) == _entity.end()) {
                std::cout << "error name not found" << std::endl;
                return newEntity;
            }
            newEntity = std::make_shared<entity::Entity>();
            for (auto e : _entity[name]) {
                newEntity->_funcComp.insert(std::pair<std::string, std::function<void(RTypeProtocol::Message&)>>(e, _action[e]));
            }
            newEntity->_name = name;
            // LibGraĥique => pour récupérer toutes les données lié à l'affichage

            newEntity->myGraph = lib->factoryData("Ship");

            // Initialiser par défaut de la vitesse / direction / position
            return newEntity;
        }
    }
}