#include "hero/class/wizard/Necromancer.h"

namespace He_ARC::rpg {
    /// @brief Necromancer standard parameterized constructor
    /// @param _strength Value of necromancer's strength
    /// @param _agility Value of necromancer's agility
    /// @param _intelligence Value of necromancer's intelligence
    /// @param _hp Value of necromancer's hit points
    /// @param _mana Value of necromancer's mana points
    /// @param _weapon Points to necromancer's right hand weapon
    /// @param _pObject Points to necromancer's left hand object
    /// @param _name Necromancer's name
    Necromancer::Necromancer(int _strength, int _agility, int _intelligence, int _hp, int _mana, Weapon *_weapon, IObject *_pObject, string _name) : 
    Wizard(_strength, _agility, _intelligence, _hp, _mana, _weapon, _pObject, _name) {}

    /// @brief Basic necromancer spell cast
    void Necromancer::raiseUndeads() {
        if (mana > 1)
        {
            cout << "Rigid paradise" << endl;
            mana-=2;
        }
    }
}