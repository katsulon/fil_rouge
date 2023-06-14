#include "hero/class/Wizard.h"

namespace He_ARC::rpg {
    /// @brief Wizard standard parameterized constructor
    /// @param _strength Value of wizard's strength
    /// @param _agility Value of wizard's agility
    /// @param _intelligence Value of wizard's intelligence
    /// @param _hp Value of wizard's hit points
    /// @param _mana Value of wizard's mana points
    /// @param _weapon Points to wizard's right hand weapon
    /// @param _pObject Points to wizard's left hand object
    /// @param _name Wizard's name
    Wizard::Wizard(int _strength, int _agility, int _intelligence, int _hp, int _mana, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _pObject, _name), mana(_mana) {
        // Loading textures and defining frame size
        frameSize = 32;
        immobileTexture = "res/sprites/character/wizard/wizard.png";
        walkTexture = "res/sprites/character/wizard/wizard_walk.png";
    }

    /// @brief Basic wizard spell cast
    void Wizard::castSpell() {
        if (mana > 1)
        {
            cout << "Fireball!" << endl;
            mana-=2;
        }
    }

    /// @brief Method to show wizard's stats.
    void Wizard::show() const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout << "MP            " << mana << endl;
        cout <<  endl;  
    }

    /// @brief Method to allow overriding ostream in derived classes.
    /// @param where Ostream
    void Wizard::print(ostream& where) const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout << "MP            " << mana << endl;
        cout <<  endl;  
    }

    /// @brief Wizard interaction with another hero
    /// @param otherHero Reference to other hero
    void Wizard::interact(const Hero& otherHero)
    {
        cout << "Greetings, valiant " << otherHero.getName() << ". My name is " << name << ". It is my pleasure to meet you." << endl;
    }
}