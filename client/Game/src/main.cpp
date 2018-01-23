#include <lua.hpp>
#include <LuaBridge.h>
#include <iostream>
#include <memory>
#include <typeindex>
#include "../../../utils/GameEngine/include/Entity.hpp"

int main() {
//    Core *core;
//    try { core = new Core(); }
//    catch (const std::exception &e) {std::cerr << "Error: " << e.what() << std::endl;}
//    core->start();
//    UgandaEngine::MapConfHandler mapConfHandler;
//    try {
//        mapConfHandler.loadMap("../assets/map1/mothership.json");
//        mapConfHandler.getMap();
//    } catch (const std::exception &e) { std::wcerr << e.what() << std::endl; }


    //Test création entity
//    UgandaEngine::entity::Entity *e = new UgandaEngine::entity::Entity;
//
//    UgandaEngine::TestComponent test;
//    std::shared_ptr<UgandaEngine::TestComponent> testComponent = std::make_shared<UgandaEngine::TestComponent>(test);
//
//    testComponent->setPhrase("Ceci est un test!");
//    e->addComponent(std::type_index(typeid(UgandaEngine::TestComponent)), testComponent);
//
//    std::weak_ptr<UgandaEngine::TestComponent> getter = e->get<UgandaEngine::TestComponent>();
//    std::cout << getter.lock().get()->getPhrase() << std::endl;

    //Test
    lua_State* L = luaL_newstate();
    luaL_dofile(L, "../assets/ghost.lua");
    luaL_openlibs(L);
    lua_pcall(L, 0, 0, 0);
    luabridge::LuaRef ghostRef = luabridge::getGlobal(L, "ghost");
    for(int i = 0; i < ghostRef.length(); ++i) {
        luabridge::LuaRef ghostTableRef = ghostRef[i+1];
        std::string componentName = ghostTableRef["componentName"].cast<std::string>();
        std::cout << componentName << std::endl;
    }
    return 0;
}