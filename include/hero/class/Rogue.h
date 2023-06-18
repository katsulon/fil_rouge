#pragma once

#include "hero/Hero.h"

namespace He_ARC::rpg {
    /**
    * @brief Derived class for rogues
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class Rogue : public Hero {
        public:
            Rogue(int=100, Weapon *weapon=new Weapon(100, "Rusty Knife"), IObject *pObject=nullptr, string="Locke");
            void interact(const Hero&) override;
    };
}