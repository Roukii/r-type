//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_GAMEENGINE_HPP
#define R_TYPE_GAMEENGINE_HPP

#include "AEntity.hpp"
#include "EngineDefinitions.hpp"

namespace UgandaEngine {

    //TODO: Ajouter le chargement de la lib graphique, des lua, conf etc... Pour faciliter le taff
    class AGameEngine {
        /*
         * Variables
         */

    protected:
        //List of entities
        std::vector<AEntity> _Entities;


        /*
         * Constructor and destructor
         */
    public:
        AGameEngine();
        ~AGameEngine() = default;


        /*
         * Function and methods
         */

        //Start function
    public:
        void start();

        //Event functions
        void addEntity(const AEntity &newEntity);


        /*
         * Virtual functions
         */
    public:
        //Game Loop
        virtual void gameLoop() = 0;

        //Boolean to check loop condition
        virtual bool isAlive() = 0;

        //Generic functions to draw
        //TODO: Peut-être foutre ça dans une classe dédiée au graphique qu'on charge celon une lib graphique justement
        virtual void drawWindow() = 0;

        //Key handling
        virtual KeyInput input() = 0;
    };
}


#endif //R_TYPE_GAMEENGINE_HPP
