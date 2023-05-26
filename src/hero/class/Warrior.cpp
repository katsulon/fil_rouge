#include "hero/class/Warrior.h"

namespace He_ARC::rpg {
    Warrior::Warrior(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _pObject, _name) {
        frameSize = 48;
        immobileTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac.png";
        idleTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_idle.png";
        walkTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_walk.png";
        attackTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_attack.png";
        gethurtTexture =  "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_gethurt.png";
        knockoutTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_knockout.png";
    }

    void Warrior::interact(const Hero& otherHero)
    {
        cout << "Hey you there, " << otherHero.getName() << ", right? The name's " << name << ". Nice to meet cha." << endl;
    }
}