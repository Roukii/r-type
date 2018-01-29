//
// Created by sentrance on 19/01/18.
//

#ifndef R_TYPE_TESTCOMPONENT_HPP
#define R_TYPE_TESTCOMPONENT_HPP

#include <string>
#include <iostream>
#include "AComponent.hpp"

namespace UgandaEngine {
    class TestComponent : public AComponent {
        /*
         * Variables
         */
    public:
        std::string _phrase;

        /*
         * Constructor and destructor
         */
    public:
        TestComponent() = default;

        /*
         * Function and methods
         */
    public:
        void setPhrase(const std::string &phrase) {
            _phrase = phrase;
        }

        std::string getPhrase() const {
            return _phrase;
        }
    };
}

#endif //R_TYPE_TESTCOMPONENT_HPP
