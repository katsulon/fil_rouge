#include <iostream>
#include "hero/Hero.h"

namespace He_ARC::rpg {
    // Constructors

    /// @brief Hero standard parameterized constructor
    /// @param _strength Value of hero's strength
    /// @param _agility Value of hero's agility
    /// @param _intelligence Value of hero's intelligence
    /// @param _hp Value of hero's hit points
    /// @param _weapon Points to hero's right hand weapon
    /// @param _pObject Points to hero's left hand object
    /// @param _name Hero's name
    Hero::Hero(int _strength, int _agility, int _intelligence, int _hp, Weapon *_weapon, IObject *_pObject, string _name) : 
    strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name), weapon(_weapon), pObject(_pObject) {}

    //Getters

    /// @brief Gets current position of hero. An offset variable has been added to account for different position if hero's sprite has been flipped.
    /// @return Current position of hero.
    sf::Vector2f Hero::getPos() const { 
        int flipOffset = 0;
        if (flipped) {
            flipOffset = (frameSize-16/2+16/2/4)*4;
        }
        
        return sf::Vector2f(sprite.getPosition().x-(-frameSize/2+16/4*3)*4-flipOffset, sprite.getPosition().y-(-frameSize+16)*4); 
    }

    // Setters

    /// @brief Sets value of heros's strength. If value below 0, sets it to 0.
    /// @param strength Strength value of hero
    void Hero::setStrength(int strength) {
        if (strength > -1)
            this->strength = strength;
        else
            this->strength = 0; 
    }
    /// @brief Sets value of heros's agility. If value below 0, sets it to 0.
    /// @param agility Agility value of hero
    void Hero::setAgility(int agility) {
        if (agility > -1)
            this->agility = agility;
        else
            this->agility = 0; 
    }
    /// @brief Sets value of heros's intelligence If value below 0, sets it to 0.
    /// @param intelligence Intelligence value of hero
    void Hero::setIntelligence(int intelligence) {
        if (intelligence > -1)
            this->intelligence = intelligence;
        else
            this->intelligence = 0; 
    }
    /// @brief Sets value of heros's hit points. If value below 0, sets it to 0.
    /// @param hp Hit points value of hero
    void Hero::setHealth(int hp) {
        if (hp > -1)
            this->hp = hp;
        else
            this->hp = 0; 
    }
    // SFML setters

    /// @brief Sets position of current hero, taking into account frame sizes.
    /// @param x X coordinate of the new position
    /// @param y Y coordinate of the new position
    void Hero::setPos(float x, float y) {
        if (!flipped) {
            sprite.setPosition(x+(-frameSize/2+16/4*3)*4, y+(-frameSize+16)*4);
        }
        else {
            sprite.setPosition(x+(-frameSize/2+16/4*3)*4+(frameSize-16/2+16/2/4)*4, y+(-frameSize+16)*4);
        }
    }

    // Methods
    
    void Hero::walk(float const& dt, const float dir_x, const float dir_y, int frameRate) {
        float currentX = getPos().x;
        float currentY = getPos().y;

        setPos(currentX+=(speed*dir_x*dt), currentY+=(speed*dir_y*dt));
        
        currentState=Move;
        if ((dir_x < 0) && (flipped == false)) {
            flipped = true;
            loadTexture(frameRate, flipped);
        }
        else if ((dir_x > 0) && (flipped == true)) {
            flipped = false;
            loadTexture(frameRate, flipped);
        }
    }

    // Method now virtual pure, therefore no longer necessary
    /*void Hero::interact(const Hero& otherHero) {
        cout << "Greetings, valiant " << otherHero.name << "! My name is " << name << "." << endl;
    }*/

    /// @brief Method to show hero's stats.
    void Hero::show() const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout <<  endl;
    }

    /// @brief Method to allow overriding ostream in derived classes.
    /// @param where Ostream
    void Hero::print(ostream& where) const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "strength      " << strength << endl;
        cout << "agility       " << agility << endl;
        cout << "intelligence  " << intelligence << endl;
        cout << "HP            " << hp << endl;
        cout <<  endl;
    }

    /// @brief Shows hero's stats using "<<" operator.
    /// @param s Ostream
    /// @param hero Hero whose stats are to be shown
    /// @return Ostream
    ostream& operator<<(ostream& s, const Hero& hero) {
        hero.print(s);
        return s;
    }

    /// @brief Hero deconstructor. Deletes pointers to right hand weapon and left hand objet.
    Hero::~Hero() {
        delete weapon;
        delete pObject;
    }
}