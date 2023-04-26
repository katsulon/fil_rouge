#pragma once

#include "hero/class/Wizard.h"

namespace He_ARC::rpg {
    class Necromancer : public Wizard {
        public:
            Necromancer(int=3, int=7, int=10, int=100, int=4, Weapon* weapon=new Weapon(100, "Old Staff"), IObject *pObject=new Potion(100, "Potent Healing Potion"), string="Seiga");
            void raiseUndeads();
    };
}