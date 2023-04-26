#include "hero/class/wizard/Necromancer.h"

namespace He_ARC::rpg {
    Necromancer::Necromancer(int _strength, int _agility, int _intelligence, int _hp, int _mana, Weapon *_weapon, IObject *_pObject, string _name) : 
    Wizard(_strength, _agility, _intelligence, _hp, _mana, _weapon, _pObject, _name) {}


    void Necromancer::raiseUndeads() {
        if (mana > 1)
        {
            cout << "Rigid paradise" << endl;
            mana-=2;
        }
    }
}