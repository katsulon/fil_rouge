#include "hero/class/Rogue.h"

namespace He_ARC::rpg {
    Rogue::Rogue(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _name) {}

    void Rogue::loadTexture(state currentState, int frameRate) {
        int frameSize = 32;
        string srcTexture;
        switch (currentState) {
            case immobile:
                srcTexture = "res/sprites/character/free_fighters/GLADIUS/gladius.png";
                break;
            case idle:
                srcTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_idle.png";
                break;
            case move:
                srcTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_walk.png";
                break;
            case attack:
                srcTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_attack.png";
                break;
            case gethurt:
                srcTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_gethurt.png";
                break;
            case knockout:
                srcTexture = "res/sprites/character/free_fighters/GLADIUS/gladius_knockout.png";
                break;
        }
        texture.loadFromFile(srcTexture);
        animFrame++;
        animFrame%=frameRate;
        int maxX=texture.getSize().x;
        int maxY=texture.getSize().y;
        xPos+=(animFrame%(frameRate/10)==0)*frameSize;    
        xPos%=maxX;
        if (xPos%maxX==0)
        {
            yPos+=(animFrame%(frameRate/10)==0)*frameSize;    
            yPos%=maxY;
        }

        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(xPos, yPos, frameSize, frameSize));
        //sprite.setColor(sf::Color(255, 255, 255, 200)); set sprite color
        sprite.setScale(4,4);
    }

    void Rogue::interact(const Hero& otherHero)
    {
        cout << "Oh, you're a new face. " << otherHero.getName() << ", right? I'm " << name << ". Nice to meet cha." << endl;
    }
}