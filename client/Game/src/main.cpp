#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Ship.hpp"
#include "../include/Menu.hpp"
#include "../../State/include/Core.hpp"
#include "../../../utils/GameEngine/include/MapConfHandler.hpp"

int main() {
//    sf::RenderWindow	win(sf::VideoMode(1920, 1080), "R-Type");
////    Ship			ship;
//    Menu          menu;
//
//    while (win.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (win.pollEvent(event)) {
//            // Close window: exit
//            if (event.type == sf::Event::Closed)
//                win.close();
//            menu.handleKeys(event);
//        }
//        // Clear screen
//        win.clear();
//
////        ship.update(event);
////        //Display Ship Sprite
////        win.draw(ship);
//        // Update the window
//        win.draw(menu.getSprite()[0]);
//        win.draw(menu.getSprite()[1]);
//        win.draw(menu.getText()[0]);
//        win.draw(menu.getText()[1]);
//        win.draw(menu.getText()[2]);
//        win.draw(menu.getText()[3]);
//        win.display();
//    }
//    Core *core;
//    try { core = new Core(); }
//    catch (const std::exception &e) {std::cerr << "Error: " << e.what() << std::endl;}
//    core->start();
    UgandaEngine::MapConfHandler mapConfHandler;
    try {
        mapConfHandler.loadMap("../assets/map1/mothership.json");
        mapConfHandler.getMap();
    } catch (const std::exception &e) { std::wcerr << e.what() << std::endl; }

    return 0;
}