//
// Created by sentrance on 14/01/18.
//

#include "MapConfHandler.hpp"

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
            _map.setBgTexture(pairValue.second);
        else if (pairValue.first == "map")
            _map.createMap(pairValue.second);
        else
            _map.loadMapTile(pairValue.second);

        std::cout << "[!] Read map value: " << pairValue.first<< " = " << pairValue.second<< std::endl;
    }
}




