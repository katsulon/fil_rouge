#include "weapon/Weapon.h"

namespace He_ARC::rpg {
    Weapon::Weapon(int _damage, string _name): damage(_damage), name(_name) {}
    Weapon::Weapon(const Weapon& weapon) {
        this->damage = weapon.damage;
        this->name = weapon.name;
    }


    void Weapon::setDamage(int damage) {
        if (damage > -1)
            this->damage = damage;
        else
            this->damage = 0;
    }
    void Weapon::setName(string name) {
        this->name = name;
    }


    Weapon& Weapon::operator=(const Weapon& weapon) {
        if(this != &weapon) {
            this->setDamage(weapon.damage);
            this->setName(weapon.name);
        }
        return *this;
    }
}