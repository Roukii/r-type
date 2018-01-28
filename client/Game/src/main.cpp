#include <iostream>
#include "Core.hpp"
#include "RTypeException.hpp"

int main() {
    try {
        std::shared_ptr<Core> core = std::make_shared<Core>();
        core->start();
    }
    catch (RTypeException &e){
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}