#pragma once

#include "hero/object/IObject.h"

namespace He_ARC::rpg {
    class Potion : public IObject {
    private:
        int power;
        string name;
    public:
        Potion(int=10, string="Residual Healing Potion");
        Potion(const Potion&);
        string getName() const override { return name; };
        int getFeature() const override { return power; };
        void setFeature(int);
        void setName(string name) { this->name = name; }
        Potion& operator=(const Potion&);
        ~Potion() = default;
    };
}