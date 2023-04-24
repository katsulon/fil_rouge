#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "hero/object/IObject.h"
#include "hero/object/weapon/Weapon.h"

using namespace std;

namespace He_ARC::rpg {
    /**
    * Base class for playable characters and combat NPC
    * @author Elisa Goloviatinski
    * @version 4.0
    */
    class Hero {
    protected:
        int strength = 0;
        int agility = 0;
        int intelligence = 0;
        int hp = 0;
        string name = "no_name";
        Weapon *weapon = nullptr;
        //SFML variables
        sf::Texture texture;
        sf::Sprite sprite;
        bool flipped = false;
        int counter = 1;
        int animFrame = 0;
        int xPos = 0;
        int yPos = 0;
        float speed = 300.f;
    public:
        Hero() = default;
        Hero(int, int, int, int, Weapon*, string);
        //Hero(const Hero&); //not necessary

        //getters
        int getStrength() const { return strength; }
        int getAgility() const { return agility; }
        int getIntelligence() const { return intelligence; }
        int getHealth() const { return hp; }
        string getName() const { return name; }
        Weapon getWeapon() const { return *weapon; }
        //SFML getters
        sf::Texture& getTexture() { return texture; }
        sf::Sprite getSprite() const { return sprite; }
        float getSpeed() const { return speed; } 
        bool getSpriteState() const { return flipped; }
        sf::Vector2f getPos() const { return sprite.getPosition(); }

        //setters
        void setStrength(int);
        void setAgility(int);
        void setIntelligence(int);
        void setHealth(int);
        void setName(string name) { this->name = name; }
        void setWeapon(Weapon *weapon) { this->weapon = weapon; }
        //SFML setters
        void setSpeed(float speed) { this->speed = speed; }
        void setSpriteState(bool flipped) { this->flipped = flipped; }
        void setCounter(int counter) { this->counter = counter; }

        //SFML methods
        enum state { immobile, idle, move, attack, gethurt, knockout };
        state currentState = immobile;
        virtual void loadTexture(int, bool) = 0;
        void setPos(int, int);
        void walk(const float &, const float, const float, int);
        //methods
        virtual void interact(const Hero&) = 0;
        virtual void show() const;
        virtual void print(ostream& where) const;
        friend ostream& operator<<(ostream&, const Hero&);
        virtual ~Hero();
    };
}