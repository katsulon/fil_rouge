#include "class/Wizard.h"

namespace He_ARC::rpg {
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, int _mana, Weapon *_weapon, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _name), mana(_mana) {}


    void Wizard::castSpell() {
        if (mana > 1)
        {
            cout << "Fireball!" << endl;
            mana-=2;
        }
    }

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

    void Wizard::interact(const Hero& otherHero)
    {
        cout << "Greetings, valiant " << otherHero.getName() << ". My name is " << name << ". It is my pleasure to meet you." << endl;
    }

    ostream& operator<<(ostream& s, const Wizard& wizard) {
        return s
        << "==========================" << endl
        << "HERO           " << wizard.name << endl
        << "==========================" << endl
        << "strength       " << wizard.strength << endl
        << "agility        " << wizard.agility << endl
        << "intelligence   " << wizard.intelligence << endl
        << "HP             " << wizard.hp << endl
        << "MP             " << wizard.mana << endl
        <<  endl;
    }
}