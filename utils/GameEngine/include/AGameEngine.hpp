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
#include <dlfcn.h>
#include <lua.hpp>
#include <LuaBridge.h>
#include "Entity.hpp"
#include "LibGraph.hpp"
#include "FactoryEntity.hpp"
#include "../../../client/Lib/include/ILib.hpp"


namespace UgandaEngine {
    // TODO: Renommer la classe en GameEngine car ce n'est pas une abstract


    class AGameEngine {
        /*
         * Variables
         */
    private:
        //List of entities
        std::vector<entity::Entity> _Entities;

    public:
        std::shared_ptr<ILib>                       libGraph;
        std::shared_ptr<LibGraph>                   graph;
        std::shared_ptr<Factory::FactoryEntity>     factory;
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

        UgandaEngine::entity::Entity *createEnWithLua(const std::string &filePath,
                                                                      const std::string &entityName);
    };

}

#endif //R_TYPE_GAMEENGINE_HPP
