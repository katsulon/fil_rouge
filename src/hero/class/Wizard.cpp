#include "hero/class/Wizard.h"

namespace He_ARC::rpg {
    // Constructor

    /// @brief Wizard standard parameterized constructor
    /// @param _hp Value of wizard's hit points
    /// @param _mana Value of wizard's mana points
    /// @param _weapon Points to wizard's right hand weapon
    /// @param _pObject Points to wizard's left hand object
    /// @param _name Wizard's name
    Wizard::Wizard(int _hp, int _mana, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_hp, _weapon, _pObject, _name), mana(_mana) {
        // Loading textures and defining frame size
        frameSize = 32;
        immobileTexture = "res/sprites/character/wizard/wizard.png";
        walkTexture = "res/sprites/character/wizard/wizard_walk.png";
    }

    // Setter

    /// @brief Sets value of wizard's mana. If value below 0, sets it to 0.
    /// @param mana Hit points value of hero
    void Wizard::setMana(int mana) {
        try {
            if (mana > -1) {
                this->mana = mana;
            }
            else {
                throw "Negative value";
            }
        }
        catch(const char* negativeValue) {
            cout << negativeValue << endl;
            this->mana = 0;
        }
    }

    // Methods

    /// @brief Basic wizard spell cast
    void Wizard::castSpell() {
        try {
            if (mana > 1) {
                cout << "Fireball!" << endl;
                mana-=2;
            }
            else {
                throw "Not enough mana";
            }
        }
        catch(const char* mana) {
            cout << mana << endl;
        }
    }

    /// @brief Method to show wizard's stats.
    void Wizard::show() const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "speed         " << int(speed/100) << endl;
        cout << "HP            " << hp << endl;
        cout << "MP            " << mana << endl;
        cout << "Top item      " << (backpack.isNotEmpty()? backpack.getStackTop()->getName() : "None") << endl;
        cout <<  endl;  
    }

    /// @brief Method to allow overriding ostream in derived classes.
    /// @param where Ostream
    void Wizard::print(ostream& where) const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "speed         " << int(speed/100) << endl;
        cout << "HP            " << hp << endl;
        cout << "MP            " << mana << endl;
        cout << "Top item      " << (backpack.isNotEmpty()? backpack.getStackTop()->getName() : "None") << endl;
        cout <<  endl;  
    }

    /// @brief Wizard interaction with another hero
    /// @param otherHero Reference to other hero
    void Wizard::interact(const Hero& otherHero) {
        cout << "Greetings, valiant " << otherHero.getName() << ". My name is " << name << ". It is my pleasure to meet you." << endl;
    }
}