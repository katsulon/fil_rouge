#include "Hero.h"

#include <iostream>

Hero::Hero()
{ 
    strength = 3; 
    agility=7; 
    intelligence=10; 
    hp=100; 
    name="Gimli"; 
}

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