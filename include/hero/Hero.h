#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "weapon/Weapon.h"

using namespace std;

namespace He_ARC::rpg {
    /**
    * Base class for playable characters and combat NPC
    *
    * @author Elisa Goloviatinski
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
        int animFrame = 0;
        int xPos = 0;
        int yPos = 0;
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

        //setters
        void setStrength(int);
        void setAgility(int);
        void setIntelligence(int);
        void setHealth(int);
        void setName(string);
        void setWeapon(Weapon*);

        //SFML methods
        enum state { immobile, idle, move, attack, gethurt, knockout };
        virtual void loadTexture(state, int) = 0;
        void setPos(int, int);
        //methods
        virtual void interact(const Hero&) = 0;
        virtual void show() const;
        virtual void print(ostream& where) const;
        friend ostream& operator<<(ostream&, const Hero&);
        virtual ~Hero();
    };
}