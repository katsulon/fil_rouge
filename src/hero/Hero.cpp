#include "hero/Hero.h"

namespace He_ARC::rpg {
    // Constructors

    /// @brief Hero standard parameterized constructor
    /// @param _hp Value of hero's hit points
    /// @param _weapon Points to hero's right hand weapon
    /// @param _pObject Points to hero's left hand object
    /// @param _name Hero's name
    Hero::Hero(int _hp, Weapon *_weapon, IObject *_pObject, string _name) : hp(_hp), name(_name), weapon(_weapon), pObject(_pObject) {}

    Backpack Hero::backpack;

    //Getters

    /// @brief Gets current position of hero. An offset variable has been added to account for different position if hero's sprite has been flipped.
    /// @return Current position of hero.
    sf::Vector2f Hero::getPos() const { 
        int flipOffset = 0;
        if (flipped) {
            flipOffset = (frameSize-TILE_SIZE/2+TILE_SIZE/2/4)*4;
        }
        
        return sf::Vector2f(sprite.getPosition().x-(-frameSize/2+TILE_SIZE/4*3)*SCALE-flipOffset, sprite.getPosition().y-(-frameSize+TILE_SIZE)*SCALE); 
    }

    // Setters

    /// @brief Sets value of heros's hit points. If value below 0, sets it to 0.
    /// @param hp Hit points value of hero
    void Hero::setHealth(int hp) {
        try {
            if (hp > -1) {
                this->hp = hp;
            }
            else {
                throw "Negative value";
            }
        }
        catch(const char* negativeValue) {
            cout << negativeValue << endl;
            this->hp = 0;
        }
    }
    // SFML setters

    /// @brief Loads, animates and scales hero's texture.
    /// @param frameRate Game frame rate
    /// @param flipped Bool variable to check whether to flip texture or not
    void Hero::loadTexture(int frameRate, bool flipped) {
        string srcTexture;
        switch (currentState) {
            case Immobile:
                srcTexture = immobileTexture;
                break;
            case Idle:
                srcTexture = idleTexture;
                break;
            case Move:
                srcTexture = walkTexture;
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
        
        if ((flipped == true) && (counter == 0)) {
            sprite.move((frameSize-TILE_SIZE/2+TILE_SIZE/2/4)*SCALE,0.f);
            sprite.setScale(-SCALE, SCALE);
            counter=1;
        } 
        else if((flipped == false) && (counter == 1)) {
            sprite.move(-(frameSize-TILE_SIZE/2+TILE_SIZE/2/4)*SCALE,0.f);
            sprite.setScale(SCALE, SCALE);
            counter=0;
        }
    }

    /// @brief Sets position of current hero, taking into account frame sizes.
    /// @param x X coordinate of the new position
    /// @param y Y coordinate of the new position
    void Hero::setPos(float x, float y) {
        if (!flipped) {
            sprite.setPosition(x+(-frameSize/2+TILE_SIZE/4*3)*4, y+(-frameSize+TILE_SIZE)*SCALE);
        }
        else {
            sprite.setPosition(x+(-frameSize/2+TILE_SIZE/4*3)*SCALE+(frameSize-TILE_SIZE/2+TILE_SIZE/2/4)*4, y+(-frameSize+TILE_SIZE)*SCALE);
        }
    }

    // Methods
    
    /// @brief Method for updating hero textures and speed when moving
    /// @param dt Delta time
    /// @param dir_x X-direction of velocity
    /// @param dir_y Y-direction of velocity
    /// @param frameRate Game framerate
    void Hero::walk(float const& dt, const float dir_x, const float dir_y, int frameRate) {
        float currentX = getPos().x;
        float currentY = getPos().y;
        float currentSpeed = speed;

        // Normalized diagonal speed. Since only diagonal movement is possible besides horizontal or vertical, 
        //  sine of pi/4 (45*) is used for both directions as both cosine and sine of 45* have the same value.
        if ((dir_x != 0) && (dir_y != 0)) {
            currentSpeed *= sin(M_PI/4);
        }
        
        setPos(currentX+=(currentSpeed*dir_x*dt), currentY+=(currentSpeed*dir_y*dt));
        
        if ((dir_x != 0) || (dir_y != 0)) {
            currentState=Move;
        }
        
        if ((dir_x < 0) && (flipped == false)) {
            flipped = true;
            loadTexture(frameRate, flipped);
        }
        else if ((dir_x > 0) && (flipped == true)) {
            flipped = false;
            loadTexture(frameRate, flipped);
        }
    }

    /// @brief Method to show hero's stats.
    void Hero::show() const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "Speed         " << int(speed/100) << endl;
        cout << "HP            " << hp << endl;
        cout << "Top item      " << (backpack.isNotEmpty()? backpack.getStackTop()->getName() : "None") << endl;
        cout <<  endl;  
    }

    /// @brief Method to allow overriding ostream in derived classes.
    /// @param where Ostream
    void Hero::print(ostream& where) const {
        cout << "==========================" << endl;
        cout << "HERO          " << name << endl;
        cout << "==========================" << endl;
        cout << "speed         " << int(speed/100) << endl;
        cout << "HP            " << hp << endl;
        cout << "Top item      " << (backpack.isNotEmpty()? backpack.getStackTop()->getName() : "None") << endl;
        cout <<  endl;  
    }

    /// @brief Shows hero's stats by overloading the "<<" operator.
    /// @param s Ostream
    /// @param hero Hero whose stats are to be shown
    /// @return Ostream
    ostream& operator<<(ostream& s, const Hero& hero) {
        hero.print(s);
        return s;
    }

    /// @brief Hero deconstructor. Deletes pointers to right hand weapon and left hand objet as well as the contents of backpack.
    Hero::~Hero() {
        delete weapon;
        delete pObject;
        while (backpack.isNotEmpty()) {
            delete backpack.unPack();
        }
    }
}