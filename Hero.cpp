#include "Hero.h"

#include <iostream>

void Hero::interact(const Hero& autre) {
    cout << "Greetings, valiant " << autre.name << "! My name is " << this->name << "." << endl;
}
void Hero::show() {
    cout << "==========================" << endl;
    cout << "HERO: " << this->name << endl;
    cout << "==========================" << endl;
    cout << "strength: " << this->strength << endl;
    cout << "agility: " << this->agility << endl;
    cout << "intelligence: " << this->intelligence << endl;
    cout << "HP: " << this->hp << endl;
    cout <<  endl;
}

int main()
{
    Hero h1;
    Hero h2;
    h1.show();
    h1.interact(h2);
    
    return 0;
}