#include "hero/class/Wizard.h"

namespace He_ARC::rpg {
    Wizard::Wizard(int _strength, int _agility, int _intelligence, int _hp, int _mana, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _pObject, _name), mana(_mana) {
        frameSize = 32;
        immobileTexture = "res/sprites/character/wizard/wizard.png";
        walkTexture = "res/sprites/character/wizard/wizard_walk.png";
    }

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

    void Wizard::interact(const Hero& otherHero)
    {
        cout << "Greetings, valiant " << otherHero.getName() << ". My name is " << name << ". It is my pleasure to meet you." << endl;
    }
}