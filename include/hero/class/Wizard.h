#pragma once

#include "Hero.h"

namespace He_ARC::rpg {
    class Wizard : public Hero {
        protected:
            int mana;
        public:
            Wizard(int=3, int=7, int=10, int=100, int=2, Weapon *weapon=new Weapon(100, "Old Staff"), string="Gandalf");
            int getMana() const { return mana; }
            void castSpell();
            void show() const override;
            void print(ostream&) const override;
            void interact(const Hero&) override;
    };
}