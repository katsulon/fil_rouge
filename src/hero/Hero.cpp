#include <iostream>
#include "hero/Hero.h"

namespace He_ARC::rpg {
    Hero::Hero(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, string _name) : 
    strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name), weapon(_weapon) {}


    void Hero::setStrength(int strength) {
        if (strength > -1)
            this->strength = strength;
        else
            this->strength = 0; 
    }
    void Hero::setAgility(int agility) {
        if (agility > -1)
            this->agility = agility;
        else
            this->agility = 0; 
    }
    void Hero::setIntelligence(int intelligence) {
        if (intelligence > -1)
            this->intelligence = intelligence;
        else
            this->intelligence = 0; 
    }
    void Hero::setHealth(int hp) {
        if (hp > -1)
            this->hp = hp;
        else
            this->hp = 0; 
    }
    void Hero::setName(string name) {
        this->name = name;
    }
    void Hero::setWeapon(Weapon *weapon)
    {
        this->weapon = weapon;
    }

    void Hero::setPos(int x, int y) {
        sprite.setPosition(x, y);
    }

    /*void Hero::interact(const Hero& otherHero) { -> method  virtual pure, therefore not necessary
        cout << "Greetings, valiant " << otherHero.name << "! My name is " << name << "." << endl;
    }*/

    void Hero::show() const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout <<  endl;
    }

    //method to allow overriding ostream in derived classes
    void Hero::print(ostream& where) const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout <<  endl;
    }

    ostream& operator<<(ostream& s, const Hero& hero) {
        hero.print(s);
        return s;
    }

    Hero::~Hero() {
        delete weapon;
    }
}