#include "class/Warrior.h"

namespace He_ARC::rpg {
    Warrior::Warrior(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _name) {}


    void Warrior::interact(const Hero& otherHero)
    {
        cout << "Hey you there, " << otherHero.getName() << ", right? The name's " << name << ". Nice to meet cha." << endl;
    }
}