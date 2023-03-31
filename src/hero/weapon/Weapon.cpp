#include "weapon/Weapon.h"

namespace He_ARC::rpg
{
    Weapon::Weapon()
    {
        damage=10;
    }
    Weapon::Weapon(int _damage): damage(_damage) {}
    Weapon::Weapon(int _damage, string _name): damage(_damage), name(_name) {}

    int Weapon::getDamage() const
    {
        return damage;
    }

    void Weapon::setDamage(int damage)
    {
        this->damage = damage;
    }
    void Weapon::setName(string name)
    {
        this->name = name;
    }

    Weapon& Weapon::operator=(const Weapon& weapon)
    {
        if(this != &weapon)
        {
            this->setDamage(weapon.damage);
            this->setName(weapon.name);
        }
        return *this;
    }
}