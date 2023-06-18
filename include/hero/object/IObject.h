#pragma once

#include <iostream>

using namespace std;

namespace He_ARC::rpg {
    /**
    * @brief Object interface class
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class IObject {
        public: 
            /// @brief Gets current name of object.
            /// @return Object's name
            virtual string getName() const = 0;
            /// @brief Gets feature of object.
            /// @return Value of object's feature.
            virtual int getFeature() const = 0;
            /// @brief Virtual destructor
            virtual ~IObject() = default;
    };
}