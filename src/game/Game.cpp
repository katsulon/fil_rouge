#include "game/Game.h"
#include <cmath>

namespace He_ARC::rpg {
    // Initializer functions

    // Define the level with an array of tile indices
    const int level[] =
    {
        28,10,10,288,145,137,138,56,57,58,137,155,138,56,57,57,57,57,57,58,
        50,10,10,144,170,171,170,155,155,155,171,223,154,122,122,122,122,122,122,122,
        222,144,144,289,144,144,144,286,287,288,144,144,144,144,144,0,1,1,1,1,
        266,144,0,1,1,1,2,144,144,144,144,144,144,144,0,28,12,12,12,12,
        144,144,11,12,12,12,27,1,1,1,1,1,1,1,28,12,12,12,12,12,
        144,144,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        144,144,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        1,1,28,12,12,12,12,12,12,12,12,12,12,12,12,16,23,23,23,23,
        12,12,12,12,12,12,12,12,16,23,23,23,23,23,23,24,144,144,144,144,
        12,12,12,12,12,12,12,12,13,144,144,220,221,222,144,144,144,144,144,144,
        12,12,12,12,16,23,23,23,24,144,144,242,243,244,144,144,144,144,144,144,
        12,12,12,12,13,144,144,144,144,220,221,292,265,266,144,144,144,144,144,144,

    };
    // 22 tiles per row
    const int levelCliff[] =
    {
        72,72,72,72,72,72,72,56,57,58,72,72,72,56,57,57,57,57,57,58,
    };
    // 14 tiles per row
    const int levelWater[] =
    {
        10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,0,1,1,1,1,
        10,10,0,1,1,1,2,10,10,10,10,10,10,10,0,28,12,12,12,12,
        10,10,11,12,12,12,27,1,1,1,1,1,1,1,28,12,12,12,12,12,
        10,10,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        10,10,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        1,1,28,12,12,12,12,12,12,12,12,12,12,12,12,16,23,23,23,23,
        12,12,12,12,12,12,12,12,16,23,23,23,23,23,23,24,10,10,10,10,
        12,12,12,12,12,12,12,12,13,10,10,10,10,10,10,10,10,10,10,10,
        12,12,12,12,16,23,23,23,24,10,10,10,10,10,10,10,10,10,10,10,
        12,12,12,12,13,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    };
    // 11 tiles per row
    
    void Game::init() {
        window.create(sf::VideoMode(1280, 768), "Goloviatinski Fil Rouge");
        window.setFramerateLimit(frameRate);
    
        icon.loadFromFile("res/icon.png"); 
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        map.load("res/sprites/map/forest/Ground_Tileset.png", sf::Vector2u(16, 16), level, 20, 12);
        mapCliff.load("res/sprites/map/forest/Cliff.png", sf::Vector2u(16, 16), levelCliff, 20, 1);
        map.setScale(sf::Vector2f(4.0f, 4.0f));
        mapCliff.setScale(sf::Vector2f(4.0f, 4.0f));
        mapWater.load("res/sprites/map/forest/Water_Tileset.png", sf::Vector2u(16, 16), levelWater, 20, 12);
        mapWater.setScale(sf::Vector2f(4.0f, 4.0f));

        party.push_back(war1);
        party.push_back(rog1);
        party.push_back(wzd1);
        party.push_back(ncm1);

        for(Hero *member : party) {
            member->currentState=Hero::Immobile;
            member->loadTexture(frameRate, member->getSpriteState());
        }

        currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
    }

    // Constructors
    Game::Game() {
        init();
    }

    void Game::terminal() {
        for(Hero *member : party) {
            cout << *member;
        }

        war1->interact(*wzd1);
        wzd1->interact(*ncm1);
        rog1->interact(*wzd1);

        wzd1->castSpell();
        ncm1->castSpell();
        ncm1->raiseUndeads();

        cout << "Staff damage: " << wzd1->getWeapon().getFeature() << endl;
        cout << wzd1->getLeftHandItem()->getName() << endl;
        cout << ncm1->getLeftHandItem()->getName() << endl;

        Weapon *wpn1 = new Weapon();
        war1->backpack.pack(wpn1);
        Weapon *wpn2 = new Weapon(20, "Nice Bass");
        war1->backpack.pack(wpn2);
        Weapon *wpn3 = new Weapon(5, "Stick");
        war1->backpack.pack(wpn3);
        Shield *shd1 = new Shield();
        war1->backpack.pack(shd1);
        Shield *shd2 = new Shield(1000, "Stovetop");
        war1->backpack.pack(shd2);
        Potion *pot1 = new Potion();
        war1->backpack.pack(pot1);
        Potion *pot2 = new Potion(1000, "Super extra wonderful delicious elixir");
        war1->backpack.pack(pot2);
        
        while (war1->backpack.isNotEmpty()) {
            war1->backpack.unPack();
        }

        delete wpn1;
        delete wpn2;
        delete wpn3;
        delete shd1;
        delete shd2;
        delete pot1;
        delete pot2;
    }

    void Game::updateSFMLEvents() {
        sf::Time deltaTime = deltaClock.restart();
        currentHeroFlipped = currentHero->getSpriteState();
        // Player movement
        if (!collision) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                currentHero->walk(deltaTime.asSeconds(),1.f, 0.f, frameRate);
                currentHero->currentDirection = Hero::Right;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                currentHero->walk(deltaTime.asSeconds(),-1.f, 0.f, frameRate);
                currentHero->currentDirection = Hero::Left;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                currentHero->walk(deltaTime.asSeconds(),0.f, -1.f, frameRate);
                currentHero->currentDirection = Hero::Up;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                currentHero->walk(deltaTime.asSeconds(),0.f, 1.f, frameRate);
                currentHero->currentDirection = Hero::Down;
            }
        }
        while (window.pollEvent(sfEvent)) {
            sf::FloatRect visibleArea(0, 0, sfEvent.size.width, sfEvent.size.height);
            switch (sfEvent.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    // Updates the view to the new size of the window
                    window.setView(sf::View(visibleArea));
                    break;
                case sf::Event::KeyPressed:
                    if(sfEvent.key.code == sf::Keyboard::Escape)
                        window.close();
                    if (keyDown == false) {
                        if(sfEvent.key.code == sf::Keyboard::P) {
                            terminal();
                            keyDown = true;
                        }
                        // Hero selection management
                        if (sfEvent.key.code == sf::Keyboard::Num1)
                        {
                            currentHeroFlipped = currentHero->getSpriteState();
                            currentHeroPos = currentHero->getPos();
                            currentHero=war1;
                            if (currentHeroFlipped!=currentHero->getSpriteState()) {
                                if (currentHeroFlipped) {
                                    currentHero->setPos(currentHeroPos.x-currentHero->getFrameSize()*4, currentHeroPos.y);
                                    cout << "test" << endl;
                                }
                                else {
                                    currentHero->setPos(currentHeroPos.x+currentHero->getFrameSize()*4, currentHeroPos.y);
                                }
                            }
                            else {
                                currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
                            }
                            currentHero->setSpriteState(currentHeroFlipped);
                            keyDown = true;
                        }
                        if (sfEvent.key.code == sf::Keyboard::Num2)
                        {
                            currentHeroFlipped = currentHero->getSpriteState();
                            currentHeroPos = currentHero->getPos();
                            currentHero=rog1;
                            if (currentHeroFlipped!=currentHero->getSpriteState()) {
                                if (currentHeroFlipped) {
                                    currentHero->setPos(currentHeroPos.x-currentHero->getFrameSize()*4, currentHeroPos.y);
                                }
                                else {
                                    currentHero->setPos(currentHeroPos.x+currentHero->getFrameSize()*4, currentHeroPos.y);
                                }
                            }
                            else {
                                currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
                            }
                            currentHero->setSpriteState(currentHeroFlipped);
                            keyDown = true;
                            
                        }
                        if (sfEvent.key.code == sf::Keyboard::Num3)
                        {
                            currentHeroFlipped = currentHero->getSpriteState();
                            currentHeroPos = currentHero->getPos();
                            currentHero=wzd1;
                            if (currentHeroFlipped!=currentHero->getSpriteState()) {
                                if (currentHeroFlipped) {
                                    currentHero->setPos(currentHeroPos.x-currentHero->getFrameSize()*4, currentHeroPos.y);
                                }
                                else {
                                    currentHero->setPos(currentHeroPos.x+currentHero->getFrameSize()*4, currentHeroPos.y);
                                }
                            }
                            else {
                                currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
                            }
                            currentHero->setSpriteState(currentHeroFlipped);
                            keyDown = true;
                        }
                        
                    }
                    break;
                case sf::Event::KeyReleased:
                    keyDown = false;
                    currentHero->currentState=Hero::Immobile;
                    currentHero->currentDirection = Hero::None;
                    break;
            }
        }
    }

    void Game::update() {
        updateSFMLEvents();

        // Collision management
        collision = false;
        playerGridPosition.x = (currentHero->getPos().x) / (16*4);
        playerGridPosition.y = (currentHero->getPos().y - currentHero->getFrameSize()) / (16*4);
        int tileNumber = (round(playerGridPosition.y) * gridSizeX) + round(playerGridPosition.x);
        if (levelWater[tileNumber]!=10) {
            collision = true;
        }
        // Checks for collision on left or right side of window (normally should no longer be necessary after map finished)
        if ((currentHero->getPos().x+currentHero->getFrameSize()/2 - 8) < 0 || (currentHero->getPos().x+currentHero->getFrameSize()+8) > window.getSize().x){
            collision = true;
        }
        // Checks for collision on top or bottom side of window (normally should no longer be necessary after map finished)
        if ((currentHero->getPos().y-currentHero->getFrameSize() - 8) < 0 || (currentHero->getPos().y) > window.getSize().y){
            collision = true;
        }
        // Depending on diretion faced, doesn't allow player to continue in the same direction
        if (collision) {
            if (currentHero->currentDirection == Hero::Right) {
                currentHero->setPos(currentHero->getPos().x-8,currentHero->getPos().y);
            }
            else if (currentHero->currentDirection == Hero::Left) {
                currentHero->setPos(currentHero->getPos().x+currentHero->getFrameSize()*4+8,currentHero->getPos().y);
            }
            else if (currentHero->currentDirection == Hero::Up) {
                currentHero->setPos(currentHero->getPos().x,currentHero->getPos().y+8);
            }
            else if (currentHero->currentDirection == Hero::Down) {
                currentHero->setPos(currentHero->getPos().x,currentHero->getPos().y-8);
            }
        }

        // Loading textures
        currentHero->loadTexture(frameRate, currentHeroFlipped);
    }

    void Game::render() {
        window.clear(sf::Color::White);
        // Render items
        window.draw(map);
        window.draw(mapCliff);
        window.draw(mapWater);
        window.draw(currentHero->getSprite());
        window.display();
    }

    void Game::run() {
        while (window.isOpen()) {
            update();
            render();
        }
    }

    // Destructors
    Game::~Game() {
        for(Hero *member : party) {
            delete member;
        }
    }
}