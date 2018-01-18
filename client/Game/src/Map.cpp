//
// Created by alex on 1/17/18.
//

#include <fstream>
#include <iostream>

#include "Map.hpp"

UgandaEngine::Map::Map()
	: _bgTexture(std::make_shared<sf::Texture>()) {}

void		UgandaEngine::Map::createMap(const std::string &file) {
	std::ifstream fileStream(file);

	if (!fileStream)
		throw std::invalid_argument("[X] Error on loading json " + file);

	std::string line;
	while (std::getline(fileStream, line)) {
		std::vector<MapTile> mapLine;
		std::cout << "[!] Read lineMap value : " << line << std::endl;
		int i = 0;
		while (line[i]) {
			if (line[i] != ',') {
				MapTile mapTile = MapTile();
				mapTile._id = line[i] - '0';
				for (MapTile mt : _mapTiles) {
					if (mt._id == mapTile._id) {
						mapTile._isEvent = mt._isEvent;
						mapTile._isWalkable = mt._isWalkable;
						mapTile._texture = mt._texture;
					}
				}
				mapLine.push_back(mapTile);
			}
			++i;
		}
		_map.push_back(mapLine);
	}
}

void		UgandaEngine::Map::loadMapTile(const std::string &file) {
	std::ifstream fileStream(file);

	if (!fileStream)
		throw std::invalid_argument("[X] Error on loading json " + file);

	const unsigned int BUFFERSIZE = 256;
	char buffer[BUFFERSIZE];
	std::pair<std::string, std::string> pairValue;

	MapTile tile = MapTile();

	while(fileStream.peek() != '{')
		fileStream.ignore();

	while(fileStream.peek() != '}') {
		fileStream.get(buffer, BUFFERSIZE, '\"');
		fileStream.ignore();

		fileStream.get(buffer, BUFFERSIZE, '\"');
		fileStream.ignore();
		pairValue.first = buffer;

		fileStream.get(buffer, BUFFERSIZE, '\"');
		fileStream.ignore();

		fileStream.get(buffer, BUFFERSIZE, '\"');
		fileStream.ignore();
		pairValue.second = buffer;

		if (pairValue.first.empty() || pairValue.second.empty())
			break;

		if (pairValue.first == "texture")
			if (!tile._texture->loadFromFile(pairValue.second))
				throw std::invalid_argument("Error: Fail while loading texture in MapTile");
		if (pairValue.first == "id")
			try { tile._id = std::stoi(pairValue.second); } catch (std::exception const& e) { throw e; }
		if (pairValue.first == "walkable")
			tile._isWalkable = pairValue.second == "true";
		if (pairValue.first == "event")
			tile._isEvent = pairValue.second == "true";

		std::cout << "[!] Read mapTile value: " << pairValue.first<< " = " << pairValue.second<< std::endl;
	}
	_mapTiles.push_back(tile);
}

void 		UgandaEngine::Map::setBgTexture(const std::string& texture) {
	if (!_bgTexture->loadFromFile(texture))
		throw std::invalid_argument("Error: Cannot load background texture");
	_bgSprite.setTexture(*_bgTexture);
}

void 		UgandaEngine::Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_bgSprite, states);
}