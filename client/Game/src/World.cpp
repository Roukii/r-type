//
// Created by alex on 1/15/18.
//

#include "World.hpp"

void 		World::loadNewMap(const std::string& jsonFilePath) {
	if (!jsonFilePath.empty())
		_map.loadMap(jsonFilePath);
}