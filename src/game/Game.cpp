#include "game/Game.h"
#include <cmath>

namespace He_ARC::rpg {
    // Initializer functions

    // Define the level with an array of tile indices (20x12)
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
    // 22 tiles per row in texture
    const int levelCliff[] =
    {
        72,72,72,72,72,72,72,56,57,58,72,72,72,56,57,57,57,57,57,58,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
        72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,72,
    };
    // 14 tiles per row in texture, 72 is transparent
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
    // 11 tiles per row in texture, 10 is transparent
    
    void Game::init() {
        window.create(sf::VideoMode(1280, 768), "Goloviatinski Fil Rouge");
        window.setFramerateLimit(frameRate);
    
        icon.loadFromFile("res/icon.png"); 
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        view = sf::View(sf::Vector2f(window.getSize().x/2, window.getSize().y/2), sf::Vector2f(window.getSize().x, window.getSize().y));
        viewWidth = view.getSize().x;
        viewHeight = view.getSize().y;

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

        currentHero->setSpriteState(currentHeroFlipped);
        currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
    }

    // Constructors

    Game::Game() {
        init();
    }

    void Game::resizeView(sf::RenderWindow &window, sf::View &view) {
        size = sf::Vector2f(window.getSize());
        // Sets min window size
        if (size.x < 800) {
            size.x = 800;
        }
        if (size.y < 600) {
            size.y = 600;
        }
        window.setSize(sf::Vector2u(size));
        aspectRatio = size.x/size.y;
        view.setCenter(viewWidth/2, viewHeight/2);
        view.setSize(sf::Vector2f(aspectRatio*viewHeight, viewHeight));
        window.setView(sf::View(view));
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

    void Game::changeCurrentHero(Hero *newHero) {
        currentHeroFlipped = currentHero->getSpriteState();
        currentHeroPos = currentHero->getPos();
        currentHero=newHero;
        currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
        currentHero->setSpriteState(currentHeroFlipped);
    }

    void Game::updateSFMLEvents() {
        deltaTime = deltaClock.restart();
        time = deltaTime.asSeconds();
        sf::Vector2f currentHeroVelocity = sf::Vector2f(0, 0);
        // Player movement 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            currentHeroVelocity.x = 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            currentHeroVelocity.x = -1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            currentHeroVelocity.y = -1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            currentHeroVelocity.y = 1.f;
        }
        currentHero->walk(time, currentHeroVelocity.x, currentHeroVelocity.y, frameRate);
        currentHeroFlipped = currentHero->getSpriteState();
        while (window.pollEvent(sfEvent)) {
            switch (sfEvent.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resizeView(window, view);
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
                            changeCurrentHero(war1);
                            keyDown = true;
                        }
                        if (sfEvent.key.code == sf::Keyboard::Num2)
                        {
                            changeCurrentHero(rog1);
                            keyDown = true;
                        }
                        if (sfEvent.key.code == sf::Keyboard::Num3)
                        {
                            changeCurrentHero(wzd1);
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

    sf::Vector2f Game::tileCollision(const int levelTiles[], int nonColliderTile, int tileNumber, sf::Vector2f gridPosition, sf::Vector2f previousPos, sf::FloatRect rectBounds) {
        sf::Vector2f currentPos = previousPos;
        sf::FloatRect tileBounds = sf::FloatRect((gridPosition.x+1)*16*4,(gridPosition.y)*16*4,16*4,16*4);
        if (levelTiles[tileNumber+1] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.x = tileBounds.left-rectBounds.width;  
            }
        }
        tileBounds = sf::FloatRect((gridPosition.x)*16*4,(gridPosition.y+1)*16*4,16*4,16*4);
        if (levelTiles[tileNumber+gridSizeX] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.y = tileBounds.top-rectBounds.height;
            }
        }    
        tileBounds = sf::FloatRect((gridPosition.x-1)*16*4,(gridPosition.y)*16*4,16*4,16*4);
        if (levelTiles[tileNumber-1] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.x = tileBounds.left+tileBounds.width;
            }
        }        
        tileBounds = sf::FloatRect((gridPosition.x)*16*4,(gridPosition.y-1)*16*4,16*4,16*4);
        if (levelTiles[tileNumber-gridSizeX] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.y = tileBounds.top+tileBounds.height;
            }
        }
        return currentPos;       
    }

    void Game::update() {
        updateSFMLEvents();
        view = window.getView();
        currentHeroPos = currentHero->getPos();
        // Collision management
        sf::FloatRect playerBounds = sf::FloatRect(currentHeroPos.x, currentHeroPos.y, 16*4,16*4);
        sf::Vector2f playerGridPosition = sf::Vector2f(0,0);
        playerGridPosition.x = round(playerBounds.left / (16*4));
        playerGridPosition.y = round(playerBounds.top / (16*4));
        int tileNumber = (playerGridPosition.y * gridSizeX + playerGridPosition.x);
        currentHeroPos = tileCollision(levelWater, 10, tileNumber, playerGridPosition, currentHeroPos, playerBounds);
        currentHeroPos = tileCollision(levelCliff, 72, tileNumber, playerGridPosition, currentHeroPos, playerBounds);

        // View movement
        sf::Vector2f currentHeroPosReal = sf::Vector2f(window.mapCoordsToPixel(currentHeroPos));
        sf::Vector2f minViewSizeWidth = sf::Vector2f(window.mapCoordsToPixel(sf::Vector2f(0,0)));
        sf::Vector2f maxViewSizeWidth = sf::Vector2f(window.mapCoordsToPixel(sf::Vector2f(gridSizeX*16*4,0)));
        sf::Vector2f viewMoveSpeed = sf::Vector2f(currentHero->getSpeed(), currentHero->getSpeed())/100.f;
        if (((currentHeroPosReal.x+currentHero->getFrameSize()/2-window.getSize().x/2) < 0) && (minViewSizeWidth.x < 0)) {
            view.move(-viewMoveSpeed.x, 0.f);
        }
        if (((currentHeroPosReal.x-currentHero->getFrameSize()/2+window.getSize().x/2) > window.getSize().x) && (maxViewSizeWidth.x > window.getSize().x)) {
            view.move(viewMoveSpeed.y, 0.f);
        }
        window.setView(view);

        // Checks for collision on left or right side of window (normally should no longer be necessary after map finished)
        /*if (currentHero->getPos().x < 0.f){
            currentHero->setPos(0.f,currentHero->getPos().y);
        }
        if ((currentHero->getPos().x+currentHero->getFrameSize()+currentHero->getFrameSize()/2) > window.getSize().x) {
            currentHero->setPos(window.getSize().x-currentHero->getFrameSize()-currentHero->getFrameSize()/2, currentHero->getPos().y);
        }
        // Checks for collision on top or bottom side of window (normally should no longer be necessary after map finished)
        if (currentHero->getPos().y < 0.f) {
            currentHero->setPos(currentHero->getPos().x,0.f);
        }
        if ((currentHero->getPos().y+currentHero->getFrameSize()+currentHero->getFrameSize()/2) > window.getSize().y) {
            currentHero->setPos(currentHero->getPos().x,window.getSize().y - currentHero->getFrameSize()-currentHero->getFrameSize()/2);
        }*/
        currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
        // Loading textures
        currentHero->loadTexture(frameRate, currentHeroFlipped);
    }

    void Game::render() {
        window.clear();

        // White rectangle for debug
        /*sf::RectangleShape test;
        test.setSize(sf::Vector2f(16*4,16*4));
        test.setPosition(currentHero->getPos().x,currentHero->getPos().y);
        test.setFillColor(sf::Color::Transparent);
        test.setOutlineColor(sf::Color::White);
        test.setOutlineThickness(1.f);
        window.draw(test);*/
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