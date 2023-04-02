#pragma once

#include <iostream>

using namespace std;

namespace He_ARC::rpg {
    class Weapon {
    private:
        int damage;
        string name;
    public:
        Weapon(int=10, string="Rusty Sword");
        Weapon(const Weapon&);
        int getDamage() const;
        void setDamage(int);
        void setName(string);
        Weapon& operator=(const Weapon&);
        ~Weapon() = default;
    };
}