//
// Created by sentrance on 09/01/18.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Core.hpp"

int main(int argc, char* argv[]) {
//
//    // Code adapted from the SFML 2 "Window" example.
//
//    sf::Window App(sf::VideoMode(800, 600), "myproject");
//
//    while (App.isOpen()) {
//        sf::Event Event;
//        while (App.pollEvent(Event)) {
//            if (Event.type == sf::Event::Closed)
//                App.close();
//        }
//        App.display();
//    }
    Core *core;

    try { core = new Core(); }
    catch (const std::exception &e) {std::cerr << "Error: " << e.what() << std::endl;}
    core->start();
}