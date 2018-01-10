//
// Created by sentrance on 10/01/18.
//

#ifndef R_TYPE_ENGINEDEFINITIONS_HPP
#define R_TYPE_ENGINEDEFINITIONS_HPP


//TODO: debug : l'utilisateur doit pouvoir charger ce qui l'intéresse (nbr de key, component type, etc...)
namespace UgandaEngine {
    enum KeyInput {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ACTION1,
        ACTION2,
        ACTION3,
        ACTION4,
        PAUSE,
        SPACE,
        ESCAPE
    };
    enum ComponentType {
        DEFAULT,
        POSITION2D,
        SPRITE,
        DAMAGE
    };
}

#endif //R_TYPE_ENGINEDEFINITIONS_HPP
