#include "../include/Hero.h"

#include <iostream>

namespace He_ARC::rpg
{
    Hero::Hero()
    { 
        strength = 0; 
        agility = 0; 
        intelligence = 0; 
        hp = 0; 
        name = "no_name"; 
    }
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name) : 
    strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name)
    {}

    void Hero::interact(const Hero& autre) {
        cout << "Greetings, valiant " << autre.name << "! My name is " << name << "." << endl;
    }
    void Hero::show() {
        cout << "==========================" << endl;
        cout << "HERO: " << name << endl;
        cout << "==========================" << endl;
        cout << "strength: " << strength << endl;
        cout << "agility: " << agility << endl;
        cout << "intelligence: " << intelligence << endl;
        cout << "HP: " << hp << endl;
        cout <<  endl;
    }
}