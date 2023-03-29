#pragma once

#include <string>

using namespace std;

namespace He_ARC::rpg
{
    class Weapon
    {
    private:
        int damage;
        string name;
    public:
        Weapon();
        Weapon(int);
        Weapon(int,string);
        Weapon(const Weapon&);
        int getDamage() const;
        void setDamage(int);
        void setName(string);
        Weapon& operator=(const Weapon&);
        ~Weapon();
    };
}