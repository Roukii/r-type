//
// Created by sentrance on 14/01/18.
//

#ifndef R_TYPE_XMLPARSER_HPP
#define R_TYPE_XMLPARSER_HPP

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>


namespace UgandaEngine {
    class MapConfHandler {
        /*
         * Inner classes
         */
    public:
        class MapTile {
        public:
            std::string _texture;
            int _id;
            bool _isWalkable;
            bool _isEvent;
        };
        class Map {
        public:
            std::vector<MapTile> _mapTiles;
            std::vector<std::vector<MapTile> > _map;
            std::string _bgTexture;

            Map() = default;
            ~Map() = default;

            void createMap(const std::string &file);
            void loadMapTile(const std::string &file);
        };

        /*
         * Variables
         */
    private:
        Map _map;

        /*
         * Constructor and destructor
         */
    public:
        MapConfHandler() = default;
        ~MapConfHandler() = default;

        /*
         * Function and methods
         */
    public:
        void loadMap(const std::string &file);
        Map getMap() { return _map; };
    };
}


#endif //R_TYPE_XMLPARSER_HPP
