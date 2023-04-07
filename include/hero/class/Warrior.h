#pragma once

#include "Hero.h"

namespace He_ARC::rpg {
    class Warrior : public Hero {
        public:
            Warrior(int=10, int=5, int=3, int=300, Weapon *weapon=new Weapon(100, "Rusty Axe"), string="Gimli");
            void loadTexture(state, int) override;
            void interact(const Hero&) override;
    };
}