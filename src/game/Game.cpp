#include "game/Game.h"

namespace He_ARC::rpg {
    //Static functions

    //Initializer functions
    // define the level with an array of tile indices
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
        window.create(sf::VideoMode(1280, 720), "Goloviatinski Fil Rouge");
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
            member->currentState=Hero::immobile;
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
    }

    void Game::updateSFMLEvents() {
        sf::Time deltaTime = deltaClock.restart();
        currentHeroFlipped = currentHero->getSpriteState();
        // Player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    currentHero->walk(deltaTime.asSeconds(),1.f, 0.f, frameRate);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    currentHero->walk(deltaTime.asSeconds(),-1.f, 0.f, frameRate);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    currentHero->walk(deltaTime.asSeconds(),0.f, -1.f, frameRate);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    currentHero->walk(deltaTime.asSeconds(),0.f, 1.f, frameRate);
        }
        while (window.pollEvent(sfEvent)) {
            sf::FloatRect visibleArea(0, 0, sfEvent.size.width, sfEvent.size.height);
            switch (sfEvent.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    // updates the view to the new size of the window
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
                        if (sfEvent.key.code == sf::Keyboard::Num1)
                        {
                            currentHeroFlipped = currentHero->getSpriteState();
                            currentHeroPos = sf::Vector2f(currentHero->getPos());
                            currentHero=war1;
                            if (currentHeroFlipped!=currentHero->getSpriteState()) {
                                currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
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
                            currentHeroPos = sf::Vector2f(currentHero->getPos());
                            currentHero=rog1;
                            if (currentHeroFlipped!=currentHero->getSpriteState()) {
                                if (currentHeroFlipped) {
                                    currentHero->setPos(currentHeroPos.x-128, currentHeroPos.y);
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
                            currentHeroPos = sf::Vector2f(currentHero->getPos());
                            currentHero=wzd1;
                            if (currentHeroFlipped!=currentHero->getSpriteState()) {
                                if (currentHeroFlipped) {
                                    currentHero->setPos(currentHeroPos.x-128, currentHeroPos.y);
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
                    currentHero->currentState=Hero::immobile;
                    break;
            }
        }
    }

    void Game::update() {
        updateSFMLEvents();

        // Loading textures
        
        
        currentHero->loadTexture(frameRate, currentHeroFlipped);

        //war1->setPos(0, 20);
        //rog1->setPos(100,0);
        //wzd1->setPos(0,0);
        //ncm1->setPos(130,100);
    }

    void Game::render() {
        window.clear(sf::Color::White);
        //Render items
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

    //Destructors
    Game::~Game() {
        for(Hero *member : party) {
            delete member;
        }
    }
}