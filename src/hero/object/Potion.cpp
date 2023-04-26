#include "hero/object/Potion.h"

namespace He_ARC::rpg {
    Potion::Potion(int _power, string _name): power(_power), name(_name) {}
    Potion::Potion(const Potion& potion) {
        this->power = potion.power;
        this->name = potion.name;
    }


    void Potion::setFeature(int power) {
        if (power > -1)
            this->power = power;
        else
            this->power = 0;
    }


    Potion& Potion::operator=(const Potion& potion) {
        if(this != &potion) {
            this->setFeature(potion.power);
            this->setName(potion.name);
        }
        return *this;
    }
}