#pragma once

#include "class/Wizard.h"

namespace He_ARC::rpg {
    class Necromancer : public Wizard {
        public:
            Necromancer(int=3, int=7, int=10, double=100, int=2, Weapon* weapon=new Weapon(100), string="Seiga");
            void raiseUndeads();
    };
}