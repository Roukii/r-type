//
// Created by Samy on 20/01/2018.
//

#ifndef R_TYPE_KEYHANDLER_HPP
#define R_TYPE_KEYHANDLER_HPP

#include <memory>

namespace key
{
    struct KeyHandler
    {
        char up;
        char down;
        char left;
        char right;
        char shoot;


        KeyHandler()
        {
            up = 'z';
            down = 's';
            left = 'q';
            right = 'd';
            shoot = ' ';
        }

    };
    static std::shared_ptr<KeyHandler> instance()
    {
        static std::shared_ptr<KeyHandler> s_instance;
        if (!s_instance)
            s_instance = std::make_shared<KeyHandler>();
        return s_instance;
    }

}
#endif //R_TYPE_KEYHANDLER_HPP
