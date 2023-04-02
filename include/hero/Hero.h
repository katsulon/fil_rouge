#pragma once

#include <iostream>
#include "weapon/Weapon.h"

using namespace std;

namespace He_ARC::rpg {
    class Hero {
    protected:
        int strength = 0;
        int agility = 0;
        int intelligence = 0;
        double hp = 0;
        string name = "no_name";
        Weapon *weapon = nullptr;
    public:
        Hero() = default;
        Hero(int, int, int, double, Weapon*, string);
        //Hero(const Hero&); //not necessary

        int getStrength() const { return strength; }
        int getAgility() const { return agility; }
        int getIntelligence() const { return intelligence; }
        double getHealth() const { return hp; }
        string getName() const { return name; }
        Weapon getWeapon() const { return *weapon; }

        virtual void interact(const Hero&);
        void show() const;
        friend ostream& operator<<(ostream&, const Hero&);
        virtual ~Hero() = default;
    };
}