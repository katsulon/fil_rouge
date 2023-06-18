#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "hero/object/IObject.h"
#include "hero/object/IObjectImpl.h"
#include "hero/inventory/Backpack.h"

using namespace std;

namespace He_ARC::rpg {
    /**
    * @brief Base class for playable characters
    * @author Elisa Goloviatinski
    * @version 5.0
    */
    class Hero {
    protected:
        int hp = 0;
        string name = "no_name";
        Weapon *weapon = nullptr;
        IObject *pObject = nullptr;
        //SFML variables
        sf::Texture texture;
        sf::Sprite sprite;
        bool flipped = false;
        int counter = 1;
        int animFrame = 0;
        int frameSize = 0;
        int xPos = 0;
        int yPos = 0;
        float speed = 350.f;
        int flipOffset;
        string immobileTexture;
        string idleTexture;
        string walkTexture;
        string attackTexture;
        string gethurtTexture;
        string knockoutTexture;
    public:
        /// @brief Default constructor
        Hero() = default;
        Hero(int, Weapon*, IObject*, string);
        Backpack backpack;

        // Getters
        int getHealth() const { return hp; }
        string getName() const { return name; }
        Weapon getWeapon() const { return *weapon; }
        IObject* getLeftHandItem() const { return pObject; }
        // SFML Getters
        sf::Texture& getTexture() { return texture; }
        sf::Sprite getSprite() const { return sprite; }
        int getFrameSize() const { return frameSize; }
        float getSpeed() const { return speed; } 
        bool getSpriteState() const { return flipped; }
        sf::Vector2f getPos() const;

        // Setters

        void setHealth(int);
        /// @brief Sets hero's name.
        /// @param name Hero's name
        void setName(string name) { this->name = name; }
        /// @brief Sets pointer to hero's right hand weapon.
        /// @param weapon Pointer to hero's weapon
        void setWeapon(Weapon *weapon) { this->weapon = weapon; }
        /// @brief Sets pointer to hero's left hand item.
        /// @param pObject Pointer to hero's item
        void setLeftHandItem(IObject *pObject) { this->pObject = pObject; }
        //SFML setters
        
        /// @brief Sets hero's speed value for position changes.
        /// @param speed Value for hero's speed
        void setSpeed(float speed) { this->speed = speed; }
        /// @brief Sets whether to flip sprite or not.
        /// @param flipped Current state of sprite
        void setSpriteState(bool flipped) { this->flipped = flipped; }

        // SFML methods
        // Enums

        enum state { Immobile, Idle, Move, Attack, Gethurt, Knockout };
        state currentState = Immobile;
        void loadTexture(int, bool);
        void setPos(float, float);
        void walk(const float &, const float, const float, int);
        // Methods

        virtual void interact(const Hero&) = 0;
        virtual void show() const;
        virtual void print(ostream& where) const;
        friend ostream& operator<<(ostream&, const Hero&);
        virtual ~Hero();
    };
}