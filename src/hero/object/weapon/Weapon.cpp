#include "hero/object/weapon/Weapon.h"

namespace He_ARC::rpg {
    // Constructor

    /// @brief Weapon standard parameterized constructor.
    /// @param _damage Weapon's damage.
    /// @param _name Weapon's name.
    Weapon::Weapon(int _damage, string _name): damage(_damage), name(_name) {}
    /// @brief Copy constructor.
    /// @param weapon Weapon from which to copy from.
    Weapon::Weapon(const Weapon& weapon) {
        this->damage = weapon.damage;
        this->name = weapon.name;
    }

    // Setter

    /// @brief Sets new damage to weapon.
    /// @param damage Damage to set.
    void Weapon::setFeature(int damage) {
        if (damage > -1)
            this->damage = damage;
        else
            this->damage = 0;
    }

    // Methods

    /// @brief Overloads "=" operator to be able to copy the current weapon to a new one, so long as it isn't the same one.
    /// @param weapon Weapon from which to copy attributes from.
    /// @return Current weapon with copied attributes.
    Weapon& Weapon::operator=(const Weapon& weapon) {
        if(this != &weapon) {
            this->setFeature(weapon.damage);
            this->setName(weapon.name);
        }
        return *this;
    }
}