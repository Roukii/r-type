//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_GAMEENGINE_HPP
#define R_TYPE_GAMEENGINE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <functional>
#include <memory>

#ifdef __linux__
#include <dlfcn.h>
#elif _WIN32
#include <boost/asio.hpp>
#include <windows.h>
#endif

#include "Entity.hpp"
#include "LibGraph.hpp"
#include "FactoryEntity.hpp"
#include "../../../client/Lib/include/ILib.hpp"
#include "../../../utils/Protocol/Message.hpp"


namespace UgandaEngine {


    class AGameEngine {
        /*
         * Variables
         */
    private:
        std::vector<Entity> _entities;

    public:
        std::shared_ptr<ILib> _libGraph;
        std::shared_ptr<LibGraph> graph;
        std::shared_ptr<Factory::FactoryEntity> _factory;

        /*
         * Constructor and destructor
         */
    public:
        AGameEngine();

        ~AGameEngine() = default;

        /*
         * Function and methods
         */
    public:
        void init(const std::vector<std::string> &component,
                  const std::map<std::string, std::vector<std::string>> &entity,
                  const std::map<std::string, std::function<void()>> &action);

    };
}

#endif //R_TYPE_GAMEENGINE_HPP
