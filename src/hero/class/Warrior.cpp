#include "hero/class/Warrior.h"

namespace He_ARC::rpg {
    /// @brief Warrior standard parameterized constructor
    /// @param _strength Value of warrior's strength
    /// @param _agility Value of warrior's agility
    /// @param _intelligence Value of warrior's intelligence
    /// @param _hp Value of warrior's hit points
    /// @param _weapon Points to warrior's right hand weapon
    /// @param _pObject Points to warrior's left hand object
    /// @param _name Warrior's name
    Warrior::Warrior(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _pObject, _name) {
        // Loading textures and defining frame size
        frameSize = 48;
        immobileTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac.png";
        idleTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_idle.png";
        walkTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_walk.png";
        attackTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_attack.png";
        gethurtTexture =  "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_gethurt.png";
        knockoutTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_knockout.png";
    }

    /// @brief Warrior interaction with another hero
    /// @param otherHero Reference to other hero
    void Warrior::interact(const Hero& otherHero)
    {
        cout << "Hey you there, " << otherHero.getName() << ", right? The name's " << name << ". Nice to meet cha." << endl;
    }
}