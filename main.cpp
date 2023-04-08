#include "imgui.h"
#include "imgui-SFML.h"
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

sf::Clock deltaClock;

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
    ImGui::SFML::Shutdown();
    return 0;
}

void init() {
    window.setFramerateLimit(frameRate);
    sf::Image icon;
    icon.loadFromFile("res/icon.png"); 
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    ImGui::SFML::Init(window);

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
        ImGui::SFML::ProcessEvent(e);
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
    ImGui::SFML::Update(window, deltaClock.restart());
    
    ImGui::ShowDemoWindow();

    war1->loadTexture(Hero::attack, frameRate);
    rog1->loadTexture(Hero::idle, frameRate);

    war1->setPos(0, 20);
    rog1->setPos(100,0);
    wzd1->setPos(0,0);
    ncm1->setPos(130,100);

    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    window.clear(sf::Color::White);
    for(Hero *member : party) {
        window.draw(member->getSprite());
    }
    ImGui::SFML::Render(window);
    window.display();
}

void clean()
{
    for(Hero *member : party) {
        delete member;
    }
}