#include <SFML/Graphics.hpp>
#include <list>
#include "Hero.h"
#include "class/ClassImpl.h"

using namespace He_ARC::rpg;

void test();

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "Goloviatinski Fil Rouge");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    if(ev.key.code == sf::Keyboard::P)
                        test();
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}

void test() {
    Warrior *war1 = new Warrior;
    Rogue *rog1 = new Rogue;
    Wizard *wzd1 = new Wizard;
    Necromancer *ncm1 = new Necromancer;
    list<Hero*> party;
    party.push_back(war1);
    party.push_back(rog1);
    party.push_back(wzd1);
    party.push_back(ncm1);
    
    for(Hero *member : party) {
        cout << *member;
    }

    war1->interact(*wzd1);
    wzd1->interact(*ncm1);
    rog1->interact(*wzd1);

    wzd1->castSpell();
    ncm1->castSpell();
    ncm1->raiseUndeads();

    for(Hero *member : party) {
        delete member;
    }
}