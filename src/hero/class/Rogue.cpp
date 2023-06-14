#include "hero/class/Rogue.h"

namespace He_ARC::rpg {
    /// @brief Rogue standard parameterized constructor
    /// @param _strength Value of rogue's strength
    /// @param _agility Value of rogue's agility
    /// @param _intelligence Value of rogue's intelligence
    /// @param _hp Value of rogue's hit points
    /// @param _weapon Points to rogue's right hand weapon
    /// @param _pObject Points to rogue's left hand object
    /// @param _name Rogue's name
    Rogue::Rogue(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _pObject, _name) {
        // Loading textures and defining frame size
        frameSize = 32;
        immobileTexture = "res/sprites/character/free_fighters/GLADIUS/gladius.png";
        idleTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_idle.png";
        walkTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_walk.png";
        attackTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_attack.png";
        gethurtTexture =  "res/sprites/character/free_fighters/GLADIUS/gladius_gethurt.png";
        knockoutTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_knockout.png";
    }

    /// @brief Rogue interaction with another hero
    /// @param otherHero Reference to other hero
    void Rogue::interact(const Hero& otherHero)
    {
        cout << "Oh, you're a new face. " << otherHero.getName() << ", right? I'm " << name << ". Nice to meet cha." << endl;
    }
}