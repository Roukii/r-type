//
// Created by youssef on 14/01/18.
//

#ifndef R_TYPE_FACTORYENTITY_HPP
#define R_TYPE_FACTORYENTITY_HPP


#include <string>
#include <functional>
#include <memory>
#include <vector>
#include <map>
#include <iostream>
#include "Entity.hpp"
#include "../../../client/Lib/include/ILib.hpp"

namespace UgandaEngine {
    namespace Factory {
        class FactoryEntity {
        public:
            FactoryEntity(const std::map<std::string, std::vector<std::string>> &entity,
                          const std::map<std::string, std::function<void()>> &action);
            std::shared_ptr<entity::Entity> create(const std::string &name, ILib *lib);
        private:
            std::map<std::string, std::vector<std::string>>     _entity;
            std::map<std::string, std::function<void()>>        _action;
        };
    }
}

#endif //R_TYPE_FACTORYENTITY_HPP
