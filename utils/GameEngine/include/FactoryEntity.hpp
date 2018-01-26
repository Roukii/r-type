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
#include "../../../utils/Protocol/Message.hpp"

namespace UgandaEngine {
    namespace Factory {
        class FactoryEntity {
        public:
            FactoryEntity(const std::map<std::string, std::vector<std::string>> &entity,
                          const std::map<std::string, std::function<void(RTypeProtocol::Message&)>> &action);
            std::shared_ptr<entity::Entity> create(const std::string &name, std::shared_ptr<ILib> lib);
        private:
            std::map<std::string, std::vector<std::string>>     _entity;
            std::map<std::string, std::function<void(RTypeProtocol::Message&)>>        _action;
        };
    }
}

#endif //R_TYPE_FACTORYENTITY_HPP
