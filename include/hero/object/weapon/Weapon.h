#pragma once

#include "hero/object/IObject.h"

namespace He_ARC::rpg {
    /**
    * @brief Derived class for weapons
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class Weapon : public IObject {
    private:
        int damage;
        string name;
    public:
        Weapon(int=10, string="Rusty Sword");
        Weapon(const Weapon&);
        /// @brief Gets current weapon name.
        /// @return Weapon's name
        string getName() const override { return name; };
        /// @brief Gets weapon's damage.
        /// @return Weapon's damage.
        int getFeature() const override { return damage; };
        void setFeature(int);
        /// @brief Sets new name to weapons.
        /// @param name New name to use.
        void setName(string name) { this->name = name; }
        Weapon& operator=(const Weapon&);
        ~Weapon() = default;
    };
}