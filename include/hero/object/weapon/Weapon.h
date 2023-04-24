#pragma once

#include "hero/object/IObject.h"

namespace He_ARC::rpg {
    class Weapon : public IObject {
    private:
        int damage;
        string name;
    public:
        Weapon(int=10, string="Rusty Sword");
        Weapon(const Weapon&);
        string getName() const override { return name; };
        int getFeature() const override { return damage; };
        void setFeature(int);
        void setName(string name) { this->name = name; }
        Weapon& operator=(const Weapon&);
        ~Weapon() = default;
    };
}