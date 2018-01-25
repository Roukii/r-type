//
// Created by sentrance on 10/01/18.
//


#include <TestComponent.hpp>
#include "../include/AGameEngine.hpp"

namespace UgandaEngine {


    void AGameEngine::init(const std::vector<std::string> &component,
                           const std::map<std::string, std::vector<std::string>> &entity,
                           const std::map<std::string, std::function<void()>> &action) {
        _factory = std::make_shared<Factory::FactoryEntity>(entity, action);
    }

    AGameEngine::AGameEngine() {
        ILib *get;
        ILib *(*external_creator)();
        void *_handle = dlopen("../build/libUGL.so", RTLD_LAZY);
        if (_handle == nullptr)
            _handle = dlopen("../build/libUGL.dll", RTLD_LAZY);
        if (_handle == nullptr)
            throw std::invalid_argument("[X]Failed to dlopen.");
        external_creator = reinterpret_cast<ILib *(*)()>(dlsym(_handle, "create_lib"));
        if (external_creator == nullptr)
            throw std::invalid_argument("[X]Fail to create external_creator.");
        get = external_creator();
        std::shared_ptr<ILib> getShared(get);
        _libGraph = getShared;
        _libGraph->init();
    }

    UgandaEngine::entity::Entity *AGameEngine::createEnWithLua(const std::string &filePath,
                                                                               const std::string &entityName) {
        lua_State* L = luaL_newstate();
        luaL_dofile(L, filePath.c_str());
        luaL_openlibs(L);
        lua_pcall(L, 0, 0, 0);
        luabridge::LuaRef reference = luabridge::getGlobal(L, entityName.c_str());
        for(int i = 0; i < reference.length(); ++i) {
            luabridge::LuaRef tableRef = reference[i+1];
            std::string componentName = tableRef["componentName"].cast<std::string>();

            std::map<std::string, AComponent>::const_iterator it = _components.find(componentName);
            if (componentName == "TestComponent") {//(it != _components.end()) {
                UgandaEngine::entity::Entity *entity = new UgandaEngine::entity::Entity;

                //Todo: changer ça en facto
                UgandaEngine::TestComponent test;
                std::shared_ptr<UgandaEngine::TestComponent> component = std::make_shared<UgandaEngine::TestComponent>(test);
                component->setPhrase(tableRef["string"].cast<std::string>());
                entity->addComponent(std::type_index(typeid(UgandaEngine::TestComponent)), component);

                std::cout << "[OK] Successfully created component [" << componentName << "]" << std::endl;
                return entity;
            }
        }
        throw std::invalid_argument("[X]Couldn't create entity [" + entityName + "] from file " + filePath);
    }

    void AGameEngine::registerComponent(const AComponent &component, const std::string &name) {
        if (_components.find(name) == _components.end())
            _components[name] = component;
    }
}