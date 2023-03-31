#pragma once

#include "Hero.h"

namespace He_ARC::rpg
{
    class Warrior : public Hero
    {
        public:
            using Hero::Hero;
            void interact(const Hero&) override;
    };
}