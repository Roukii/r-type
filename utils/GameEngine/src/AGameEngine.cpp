//
// Created by sentrance on 10/01/18.
//


#include "../include/AGameEngine.hpp"

namespace UgandaEngine {


    void AGameEngine::init(const std::vector<std::string> &component,
                           const std::map<std::string, std::vector<std::string>> &entity,
                           const std::map<std::string, std::function<void()>> &action) {
        factory = std::make_shared<Factory::FactoryEntity>(entity, action);
    }

    AGameEngine::AGameEngine() {
        ILib *get;
        ILib *(*external_creator)();
        void *_handle = dlopen("../build/libUGL.so", RTLD_LAZY);
        if (_handle == NULL)
            _handle = dlopen("../build/libUGL.dll", RTLD_LAZY);
        if (_handle == NULL)
            throw std::invalid_argument("[X]Failed to dlopen.");
        external_creator = reinterpret_cast<ILib *(*)()>(dlsym(_handle, "create_lib"));
        if (external_creator == NULL)
            throw std::invalid_argument("[X]Fail to create external_creator.");
        get = external_creator();
        std::shared_ptr<ILib> getShared(get);
        libGraph = getShared;
        libGraph->init();
    }

    void AGameEngine::initWithLua(const std::string &filePath, const std::string &entityName) {
        lua_State* L = luaL_newstate();
        luaL_dofile(L, filePath.c_str());
        luaL_openlibs(L);
        lua_pcall(L, 0, 0, 0);
        luabridge::LuaRef ghostRef = luabridge::getGlobal(L, entityName.c_str());
        for(int i = 0; i < ghostRef.length(); ++i) {
            luabridge::LuaRef ghostTableRef = ghostRef[i+1];
            std::string componentName = ghostTableRef["componentName"].cast<std::string>();
            std::cout << componentName << std::endl;
        }
    }
}