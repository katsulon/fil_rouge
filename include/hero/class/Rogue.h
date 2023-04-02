#pragma once

#include "Hero.h"

namespace He_ARC::rpg {
    class Rogue : public Hero {
        public:
            Rogue(int=5, int=10, int=7, double=100, Weapon *weapon=new Weapon(100,"Rusty Knife"), string="Locke");
            void interact(const Hero&) override;
    };
}