#include "hero/class/Rogue.h"

namespace He_ARC::rpg {
    Rogue::Rogue(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _pObject, _name) {
        frameSize = 32;
        immobileTexture = "res/sprites/character/free_fighters/GLADIUS/gladius.png";
        idleTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_idle.png";
        walkTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_walk.png";
        attackTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_attack.png";
        gethurtTexture =  "res/sprites/character/free_fighters/GLADIUS/gladius_gethurt.png";
        knockoutTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_knockout.png";
    }

    void Rogue::interact(const Hero& otherHero)
    {
        cout << "Oh, you're a new face. " << otherHero.getName() << ", right? I'm " << name << ". Nice to meet cha." << endl;
    }
}