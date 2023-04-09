#include "game/Game.h"

namespace He_ARC::rpg {
    //Static functions

    //Initializer functions
    
    void Game::init() {
        window.create(sf::VideoMode(1280, 720), "Goloviatinski Fil Rouge");
        window.setFramerateLimit(frameRate);
    
        icon.loadFromFile("res/icon.png"); 
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        party.push_back(war1);
        party.push_back(rog1);
        party.push_back(wzd1);
        party.push_back(ncm1);

        for(Hero *member : party) {
            member->loadTexture(Hero::immobile, frameRate);
        }
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
                    }
                    break;
                case sf::Event::KeyReleased:
                    keyDown = false;
                    break;
            }
        }
    }

    void Game::update() {
        updateSFMLEvents();

        war1->loadTexture(Hero::attack, frameRate);
        rog1->loadTexture(Hero::idle, frameRate);

        war1->setPos(0, 20);
        rog1->setPos(100,0);
        wzd1->setPos(0,0);
        ncm1->setPos(130,100);
    }

    void Game::render() {
        window.clear(sf::Color::White);
        //Render items
        for(Hero *member : party) {
            window.draw(member->getSprite());
        }
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