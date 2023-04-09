#include "hero/class/Warrior.h"

namespace He_ARC::rpg {
    Warrior::Warrior(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _name) {}

    void Warrior::loadTexture(state currentState, int frameRate) {
        int frameSize = 48;
        string srcTexture;
        switch (currentState) {
            case immobile:
                srcTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac.png";
                break;
            case idle:
                srcTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_idle.png";
                break;
            case move:
                srcTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_walk.png";
                break;
            case attack:
                srcTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_attack.png";
                break;
            case gethurt:
                srcTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_gethurt.png";
                break;
            case knockout:
                srcTexture = "res/sprites/character/free_fighters/BEARZODIAC/bearzodiac_knockout.png";
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

    void Warrior::interact(const Hero& otherHero)
    {
        cout << "Hey you there, " << otherHero.getName() << ", right? The name's " << name << ". Nice to meet cha." << endl;
    }
}