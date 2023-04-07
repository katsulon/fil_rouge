#include <SFML/Graphics.hpp>
#include <list>
#include "Hero.h"
#include "class/ClassImpl.h"

using namespace He_ARC::rpg;

void init();
void event();
void update();
void clean();

sf::RenderWindow window(sf::VideoMode(1280, 720), "Goloviatinski Fil Rouge");

//string const SPRITE_DIR = "res/sprites/"; currently useless
int const frameRate = 60;
//var to check whether a key has already been pressed
bool keyDown = false;

list<Hero*> party;
Warrior *war1 = new Warrior;
Rogue *rog1 = new Rogue;
Wizard *wzd1 = new Wizard;
Necromancer *ncm1 = new Necromancer;

int main() {
    init();
    while (window.isOpen()) {
        event();
        update();
    }
    clean();
    return 0;
}

void init() {
    window.setFramerateLimit(frameRate);
    sf::Image icon;
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

void terminal()
{
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

void event()
{
    sf::Event e;
    while (window.pollEvent(e))
    {
        sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
        switch (e.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                // update the view to the new size of the window
                window.setView(sf::View(visibleArea));
                break;
            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::Escape)
                    window.close();
                if (keyDown == false) {
                    if(e.key.code == sf::Keyboard::P) {
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

void update()
{
    war1->loadTexture(Hero::attack, frameRate);
    rog1->loadTexture(Hero::attack, frameRate);

    war1->setPos(0, 20);
    rog1->setPos(100,0);
    wzd1->setPos(0,0);
    ncm1->setPos(130,100);

    window.clear(sf::Color::White);
    for(Hero *member : party) {
        window.draw(member->getSprite());
    }
    window.display();
}

void clean()
{
    for(Hero *member : party) {
        delete member;
    }
}