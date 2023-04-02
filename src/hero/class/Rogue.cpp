#include "class/Rogue.h"

namespace He_ARC::rpg {
    Rogue::Rogue(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _name) {}


    void Rogue::interact(const Hero& otherHero)
    {
        cout << "Oh, you're a new face. " << otherHero.getName() << ", right? I'm " << name << ". Nice to meet cha." << endl;
    }
}