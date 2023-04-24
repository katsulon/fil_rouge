#pragma once

#include "hero/object/IObject.h"

namespace He_ARC::rpg {
    class Shield : public IObject {
    private:
        int solidity;
        string name;
    public:
        Shield(int=10, string="Wooden Shield");
        Shield(const Shield&);
        string getName() const override { return name; };
        int getFeature() const override { return solidity; };
        void setFeature(int);
        void setName(string name) { this->name = name; }
        Shield& operator=(const Shield&);
        ~Shield() = default;
    };
}