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
#include "Entity.hpp"
#include "LibGraph.hpp"
#include "FactoryEntity.hpp"


namespace UgandaEngine {
//TODO: bugfix de compilation
//    static class AGameEngine {
//        /*
//         * Variables
//         */
//    private:
//        //List of entities
//        std::vector<Entity> _Entities;
//
//    public:
//        std::shared_ptr<LibGraph>                   graph;
//        std::shared_ptr<Factory::FactoryEntity>     factory;
//        /*
//         * Constructor and destructor
//         */
//    public:
//        AGameEngine();
//        ~AGameEngine() = default;
//
//        /*
//         * Function and methods
//         */
//        //Start function
//    public:
//        void start();
//
//        //Game Loop
//        virtual void gameLoop() = 0;
//
//        //Boolean to check loop condition
//        virtual bool isAlive() = 0;
//
//        //Generic functions to draw
//        virtual void drawWindow() = 0;
//
//        //Event functions
//        //void update(float deltaTime, KeyInput keyInput);
//        void addEntity(const Entity &newEntity);
//
//        void init(const std::vector<std::string> &component,
//                  const std::map<std::string, std::vector<std::string>> &entity,
//                  const std::map<std::string, std::function> &action) const;
//
//    };

}

#endif //R_TYPE_GAMEENGINE_HPP
