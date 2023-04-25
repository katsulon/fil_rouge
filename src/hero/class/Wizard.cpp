#include "hero/class/Wizard.h"

namespace He_ARC::rpg {
    Wizard::Wizard(int _strength, int _agility, int _intelligence, int _hp, int _mana, Weapon *_weapon, IObject *_pObject, string _name) : 
    Hero(_strength, _agility, _intelligence, _hp, _weapon, _pObject, _name), mana(_mana) {}

    void Wizard::loadTexture(int frameRate, bool flipped) {
        frameSize = 32;
        string srcTexture;
        switch (currentState) {
            case immobile:
                srcTexture = "res/sprites/character/wizard/wizard.png";
                break;
            /*case idle:
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
                break;*/
        }
        texture.loadFromFile(srcTexture);
        animFrame++;
        animFrame%=frameRate;
        // Create a sprite
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
        sprite.setTextureRect(sf::IntRect(xPos, 0, frameSize, frameSize));
        //sprite.setColor(sf::Color(255, 255, 255, 200)); set sprite color
        if ((flipped == true) && (counter == 0)) {
            sprite.move(frameSize*4.f,0.f);
            sprite.setScale(-4.f,4.f);
            counter=1;
        } 
        else if((flipped == false) && (counter == 1)) {
            sprite.move(-frameSize*4.f,0.f);
            sprite.setScale(4.f,4.f);
            counter=0;
        }
    }

    void Wizard::castSpell() {
        if (mana > 1)
        {
            cout << "Fireball!" << endl;
            mana-=2;
        }
    }

    void Wizard::show() const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout << "MP            " << mana << endl;
        cout <<  endl;  
    }

    void Wizard::print(ostream& where) const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout << "MP            " << mana << endl;
        cout <<  endl;  
    }

    void Wizard::interact(const Hero& otherHero)
    {
        cout << "Greetings, valiant " << otherHero.getName() << ". My name is " << name << ". It is my pleasure to meet you." << endl;
    }
}