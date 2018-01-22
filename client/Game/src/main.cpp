#include <iostream>
#include "Core.hpp"

int main() {
    std::shared_ptr<Core> core;
    try { core = std::make_shared<Core>();}
    catch (const std::exception &e) {std::cerr << "Error: " << e.what() << std::endl;}
    core->start();
    return 0;
}