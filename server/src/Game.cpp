//
// Created by sentrance on 26/01/18.
//

#include "include/MapConfHandler.hpp"
#include "Game.hpp"

void RTypeGame::Game::init() {
    UgandaEngine::MapConfHandler mapConfHandler;
    
    mapConfHandler.loadMap("../assets/map1/mothership.json");
    mapConfHandler.getMap();
}

void RTypeGame::Game::play(double elapsedTime) {

}
