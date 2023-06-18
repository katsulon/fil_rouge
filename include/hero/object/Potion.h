#pragma once

#include "hero/object/IObject.h"

namespace He_ARC::rpg {
    /**
    * @brief Derived class for potions
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class Potion : public IObject {
    private:
        int power;
        string name;
    public:
        Potion(int=10, string="Residual Healing Potion");
        Potion(const Potion&);
        /// @brief Gets current name of potion.
        /// @return Current name.
        string getName() const override { return name; };
        /// @brief Gets power amount of potion.
        /// @return Power of potion.
        int getFeature() const override { return power; };
        void setFeature(int);
        /// @brief Sets new name for potion.
        /// @param name New name to assign.
        void setName(string name) { this->name = name; }
        Potion& operator=(const Potion&);
        ~Potion() = default;
    };
}