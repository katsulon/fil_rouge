#pragma once

#include "Hero.h"

namespace He_ARC::rpg {
    class Wizard : public Hero {
        protected:
            int mana;
        public:
            Wizard(int=3, int=7, int=10, double=100, int=2, Weapon *weapon=new Weapon(100), string="Gandalf");
            int getMana() const { return mana; }
            void castSpell();
            void show() const;
            void interact(const Hero&) override;
            friend ostream& operator<<(ostream&, const Wizard&);
    };
}