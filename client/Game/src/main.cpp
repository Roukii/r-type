#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Ship.hpp"
#include "../include/Menu.hpp"
#include "../../State/include/Core.hpp"
#include "../../../utils/GameEngine/include/MapConfHandler.hpp"

int main() {
    Core *core;
    try { core = new Core(); }
    catch (const std::exception &e) {std::cerr << "Error: " << e.what() << std::endl;}
    core->start();
//    UgandaEngine::MapConfHandler mapConfHandler;
//    try {
//        mapConfHandler.loadMap("../assets/map1/mothership.json");
//        mapConfHandler.getMap();
//    } catch (const std::exception &e) { std::wcerr << e.what() << std::endl; }

    return 0;
}