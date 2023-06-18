#pragma once

#include "hero/Hero.h"

namespace He_ARC::rpg {
    /**
    * @brief Derived class for warriors
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class Warrior : public Hero {
        public:
            Warrior(int=300, Weapon *weapon=new Weapon(100, "Rusty Axe"), IObject *pObject=nullptr, string="Gimli");
            void interact(const Hero&) override;
    };
}