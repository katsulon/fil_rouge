#include "../../include/hero/Hero.h"

namespace He_ARC::rpg
{
    Hero::Hero()
    { 
        strength = 0; 
        agility = 0; 
        intelligence = 0; 
        hp = 0; 
        name = "no_name"; 
        weapon = new Weapon();
    }

    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, Weapon *_weapon) : 
    strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name), weapon(_weapon) {}


    void Hero::interact(const Hero& otherHero) {
        cout << "Greetings, valiant " << otherHero.name << "! My name is " << name << "." << endl;
    }

    void Hero::show() const {
        cout << "==========================" << endl;
        cout << "HERO: " << name << endl;
        cout << "==========================" << endl;
        cout << "strength: " << strength << endl;
        cout << "agility: " << agility << endl;
        cout << "intelligence: " << intelligence << endl;
        cout << "HP: " << hp << endl;
        cout <<  endl;
    }


    ostream& operator<<(ostream& s, const Hero& hero)
    {
        return s
        << "==========================" << endl
        << "HERO: " << hero.name << endl
        << "==========================" << endl
        << "strength: " << hero.strength << endl
        << "agility: " << hero.agility << endl
        << "intelligence: " << hero.intelligence << endl
        << "HP: " << hero.hp << endl
        <<  endl;
    }
}