#pragma once

#include <iostream>

using namespace std;

namespace He_ARC::rpg {
    /**
    * Object interface class
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class IObject {
        public: 
            virtual string getName() const = 0;
            virtual int getFeature() const = 0;
            virtual ~IObject() = default;
    };
}