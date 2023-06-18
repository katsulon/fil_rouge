#include "hero/object/Potion.h"

namespace He_ARC::rpg {
    // Constructors

    /// @brief Potion standard parameterized constructor
    /// @param _power Potion's damage.
    /// @param _name Potion's name.
    Potion::Potion(int _power, string _name): power(_power), name(_name) {}
    /// @brief Copy constructor.
    /// @param potion Potion from which to copy from.
    Potion::Potion(const Potion& potion) {
        this->power = potion.power;
        this->name = potion.name;
    }

    // Setter

    /// @brief Sets new amount of power.
    /// @param power New power of potion.
    void Potion::setFeature(int power) {
        if (power > -1)
            this->power = power;
        else
            this->power = 0;
    }

    // Methods

    /// @brief Overloads "=" operator to be able to copy the current potion to a new one, so long as it isn't the same one.
    /// @param potion Potion from which to copy attributes from.
    /// @return Current potion with copied attributes.
    Potion& Potion::operator=(const Potion& potion) {
        if(this != &potion) {
            this->setFeature(potion.power);
            this->setName(potion.name);
        }
        return *this;
    }
}