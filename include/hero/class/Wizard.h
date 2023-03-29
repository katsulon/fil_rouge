#pragma once

#include "../Hero.h"

namespace He_ARC::rpg
{
    class Wizard : public Hero
    {
        protected:
            int mana;
        public:
            Wizard();
            Wizard(int, int, int, double, string, Weapon*, int);
            void castSpell();
            void show() const;
            //void interact(const Hero&) override;
            friend ostream& operator<<(ostream&, const Wizard&);
            //~Wizard();
    };
}