//
// Created by alex on 1/15/18.
//

#ifndef DISPLAYTESTS_WORLD_HPP
#define DISPLAYTESTS_WORLD_HPP

#include <vector>

#include "Ship.hpp"
#include "MapConfHandler.hpp"

class World {
public:
	World() = default;
	~World() = default;

	void 		loadNewMap(const std::string&);

private:
	std::vector<Ship>		_players;
	UgandaEngine::MapConfHandler	_map;
	// MAP
};

#endif //DISPLAYTESTS_WORLD_HPP
