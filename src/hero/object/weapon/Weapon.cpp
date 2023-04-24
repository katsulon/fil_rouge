#include "hero/object/weapon/Weapon.h"

namespace He_ARC::rpg {
    Weapon::Weapon(int _damage, string _name): damage(_damage), name(_name) {}
    Weapon::Weapon(const Weapon& weapon) {
        this->damage = weapon.damage;
        this->name = weapon.name;
    }


    void Weapon::setFeature(int damage) {
        if (damage > -1)
            this->damage = damage;
        else
            this->damage = 0;
    }


    Weapon& Weapon::operator=(const Weapon& weapon) {
        if(this != &weapon) {
            this->setFeature(weapon.damage);
            this->setName(weapon.name);
        }
        return *this;
    }
}