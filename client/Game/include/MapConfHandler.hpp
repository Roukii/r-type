//
// Created by sentrance on 14/01/18.
//

#ifndef R_TYPE_XMLPARSER_HPP
#define R_TYPE_XMLPARSER_HPP

#include <string>
#include <fstream>
#include <iostream>

#include "Map.hpp"


namespace UgandaEngine {
    class MapConfHandler {
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
