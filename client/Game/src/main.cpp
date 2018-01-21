//#include <iostream>
//#include <SFML/Graphics.hpp>
//
//#include "../include/Ship.hpp"
//#include "../include/Menu.hpp"
//#include "../../State/include/Core.hpp"
//#include "../../../utils/GameEngine/include/MapConfHandler.hpp"
//
//int main() {
//    Core *core;
//    try { core = new Core(); }
//    catch (const std::exception &e) {std::cerr << "Error: " << e.what() << std::endl;}
//    core->start();
////    UgandaEngine::MapConfHandler mapConfHandler;
////    try {
////        mapConfHandler.loadMap("../assets/map1/mothership.json");
////        mapConfHandler.getMap();
////    } catch (const std::exception &e) { std::wcerr << e.what() << std::endl; }
//
//    return 0;
//}
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Ship.hpp"
#include "../include/Menu.hpp"
#include "Core.hpp"
#include "../../../utils/GameEngine/include/MapConfHandler.hpp"
#include "../../../utils/GameEngine/include/Entity.hpp"
#include "../../../utils/GameEngine/include/TestComponent.hpp"

int main() {
    std::shared_ptr<Core> core;
    try { core = std::make_shared<Core>();}
    catch (const std::exception &e) {std::cerr << "Error: " << e.what() << std::endl;}
    core->start();
    UgandaEngine::MapConfHandler mapConfHandler;
//    try {
//        mapConfHandler.loadMap("../assets/map1/mothership.json");
//        mapConfHandler.getMap();
//    } catch (const std::exception &e) { std::wcerr << e.what() << std::endl; }

//    UgandaEngine::Entity *e = new UgandaEngine::Entity;
//
//    UgandaEngine::TestComponent test;
//    std::shared_ptr<UgandaEngine::TestComponent> testComponent = std::make_shared<UgandaEngine::TestComponent>(test);
//
//    testComponent->setPhrase("Ceci est un test!");
//    e->addComponent(std::type_index(typeid(UgandaEngine::TestComponent)), testComponent);
//
//    std::weak_ptr<UgandaEngine::TestComponent> getter = e->get<UgandaEngine::TestComponent>();
//    if (auto ptr = getter.lock()) {
//        std::cout << "NICE!" << std::endl;
//        std::cout << ptr->getPhrase() << std::endl;
//    } else
//        std::cout << "OUPS!" << std::endl;

    return 0;
}