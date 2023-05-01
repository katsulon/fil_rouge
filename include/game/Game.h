#pragma once

#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include <iostream>
#include <list>
#include "hero/Hero.h"
#include "hero/class/ClassImpl.h"

using namespace std;

namespace He_ARC::rpg {
    /**
    * Class for game loop
    * @author Elisa Goloviatinski
    */
    class Game {
        private:
            // Variables
            sf::RenderWindow window;
            sf::Event sfEvent;
            sf::Clock deltaClock; //Elapsed time since the last frame was drawn
            sf::Time deltaTime;
            sf::Image icon;

            // Create the tilemaps from the level definitions
            TileMap map;
            TileMap mapCliff;
            TileMap mapWater;

            int gridSizeX = 20;
            sf::Vector2f playerGridPosition = sf::Vector2f(0,0);
            sf::Vector2f tilePos = sf::Vector2f(0,0);
            sf::FloatRect tileBounds = sf::FloatRect(0,0,0,0);
            sf::RectangleShape test;

            // Var to check for collision
            bool collision = false;

            int const frameRate = 60;
            // Var to check whether a key has already been pressed
            bool keyDown = false;
            
            // Initialization of party
            list<Hero*> party;
            Warrior *war1 = new Warrior;
            Rogue *rog1 = new Rogue;
            Wizard *wzd1 = new Wizard;
            Necromancer *ncm1 = new Necromancer;

            Hero *currentHero = war1;
            sf::Vector2f currentHeroPos = sf::Vector2f(0,0);
            bool currentHeroFlipped = false; 
            Hero::direction currentHeroDirection = Hero::Right;
            float currentHeroSpeed = 300.f;
            int counterDir = 0;
            // Initialization
            void init();

        public:
            /// Constructor of Game class
            Game();

            // Methods
            /// Shows character interactions as well as events on terminal
            void terminal();
            /// SFML event handling
            void updateSFMLEvents();
            /// General updates
            void update();
            /// Game render
            void render();
            /// Runs game loop
            void run();

            /// Deconstructor of Game class
            virtual ~Game();
    };
}