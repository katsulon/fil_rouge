#include "hero/object/Shield.h"

namespace He_ARC::rpg {
    Shield::Shield(int _solidity, string _name): solidity(_solidity), name(_name) {}
    Shield::Shield(const Shield& shield) {
        this->solidity = shield.solidity;
        this->name = shield.name;
    }


    void Shield::setFeature(int solidity) {
        if (solidity > -1)
            this->solidity = solidity;
        else
            this->solidity = 0;
    }


    Shield& Shield::operator=(const Shield& shield) {
        if(this != &shield) {
            this->setFeature(shield.solidity);
            this->setName(shield.name);
        }
        return *this;
    }
}