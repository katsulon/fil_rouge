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
        int hp = 0;
        string name = "no_name";
        Weapon *weapon = nullptr;
    public:
        Hero() = default;
        Hero(int, int, int, int, Weapon*, string);
        //Hero(const Hero&); //not necessary

        int getStrength() const { return strength; }
        int getAgility() const { return agility; }
        int getIntelligence() const { return intelligence; }
        int getHealth() const { return hp; }
        string getName() const { return name; }
        Weapon getWeapon() const { return *weapon; }

        void setStrength(int);
        void setAgility(int);
        void setIntelligence(int);
        void setHealth(int);
        void setName(string);
        void setWeapon(Weapon*);

        virtual void interact(const Hero&);
        virtual void show() const;
        virtual void print(ostream& where) const;
        friend ostream& operator<<(ostream&, const Hero&);
        virtual ~Hero() = default;
    };
}