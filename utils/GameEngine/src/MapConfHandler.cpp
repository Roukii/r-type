//
// Created by sentrance on 14/01/18.
//

#include "../include/MapConfHandler.hpp"

void UgandaEngine::MapConfHandler::loadMap(const std::string &file) {
    std::ifstream fileStream(file);

    if (!fileStream)
        throw std::invalid_argument("[X] Error on loading json " + file);

    const unsigned int BUFFERSIZE = 256;
    char buffer[BUFFERSIZE];
    std::pair<std::string, std::string> pairValue;

    while(fileStream.peek() != '{')
        fileStream.ignore();

    while(fileStream.peek() != '}')
    {
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

        if (pairValue.first == "background")
            _map._bgTexture = pairValue.second;
        else if (pairValue.first == "map")
            _map.createMap(pairValue.second);
        else
            _map.loadMapTile(pairValue.second);

        std::cout << "[!] Read map value: " << pairValue.first<< " = " << pairValue.second<< std::endl;
    }
}

void UgandaEngine::MapConfHandler::Map::loadMapTile(const std::string &file){
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
            tile._texture = pairValue.second;
        if (pairValue.first == "id")
            try { tile._id = std::stoi(pairValue.second); } catch (std::exception const& e) { throw e; }
        if (pairValue.first == "walkable")
            tile._isWalkable = pairValue.second == "true";
        if (pairValue.first == "event")
            tile._isEvent = pairValue.second == "true";

        std::cout << "[!] Read mapTile value: " << pairValue.first<< " = " << pairValue.second<< std::endl;
    }
    _mapTiles.push_back(std::make_shared<MapTile>(tile));
}

void UgandaEngine::MapConfHandler::Map::createMap(const std::string &file) {
    std::ifstream fileStream(file);

    if (!fileStream)
        throw std::invalid_argument("[X] Error on loading json " + file);

    std::string line;
    while (std::getline(fileStream, line)) {
        std::vector<std::weak_ptr<MapTile> > mapLine;
        std::cout << "[!] Read lineMap value : " << line << std::endl;
        int i = 0;
        while (line[i]) {
            if (line[i] != ',') {
                for (const std::shared_ptr<MapTile> &mt : _mapTiles) {
                    if (mt->_id == line[i]) {
                        std::weak_ptr<MapTile> cpy = mt;
                        mapLine.push_back(cpy);
                    }
                }
            }
            ++i;
        }
        _map.push_back(mapLine);
    }
}
