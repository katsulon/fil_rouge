#pragma once

#include "hero/Hero.h"

namespace He_ARC::rpg {
    /**
    * @brief Derived class for wizards
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class Wizard : public Hero {
        protected:
            int mana;
        public:
            Wizard(int=100, int=2, Weapon *weapon=new Weapon(100, "Old Staff"), IObject *pObject=new Potion(10), string="Gandalf");
            /// @brief Gets current amount of mana.
            /// @return Mana points.
            int getMana() const { return mana; }
            void setMana(int);
            void castSpell();
            void show() const override;
            void print(ostream&) const override;
            void interact(const Hero&) override;
    };
}