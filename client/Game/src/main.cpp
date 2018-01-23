#include <iostream>
#include "Core.hpp"

int main() {
    try {
        std::shared_ptr<Core> core = std::make_shared<Core>();
        core->start();
    } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
//    //Test création entity
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
}