#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Ship.hpp"
#include "../include/Menu.hpp"
#include "../../../utils/GameEngine/include/MapConfHandler.hpp"
#include "../../../utils/GameEngine/include/Entity.hpp"
#include "../../../utils/GameEngine/include/TestComponent.hpp"

#include <LuaBridge.h>
#include <iostream>
#include <lua.h>
#include <lua.hpp>
//extern "C" {
//# include "lua.h"
//# include "lauxlib.h"
//# include "lualib.h"
//}

using namespace luabridge;

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

    UgandaEngine::Entity *e = new UgandaEngine::Entity;

    UgandaEngine::TestComponent test;
    std::shared_ptr<UgandaEngine::TestComponent> testComponent = std::make_shared<UgandaEngine::TestComponent>(test);

    testComponent->setPhrase("Ceci est un test!");
    e->addComponent(std::type_index(typeid(UgandaEngine::TestComponent)), testComponent);

    std::weak_ptr<UgandaEngine::TestComponent> getter = e->get<UgandaEngine::TestComponent>();
    std::cout << getter.lock().get()->getPhrase() << std::endl;

    //
    lua_State* L = luaL_newstate();
    luaL_dofile(L, "script.lua");
    luaL_openlibs(L);
    lua_pcall(L, 0, 0, 0);
    LuaRef s = getGlobal(L, "testString");
    LuaRef n = getGlobal(L, "number");
    std::string luaString = s.cast<std::string>();
    int answer = n.cast<int>();
    std::cout << luaString << std::endl;
    std::cout << "And here's our number:" << answer << std::endl;


    return 0;
}