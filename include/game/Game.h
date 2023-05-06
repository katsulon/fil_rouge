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
            float time;
            sf::Image icon;

            // Create the tilemaps from the level definitions
            TileMap map;
            TileMap mapCliff;
            TileMap mapWater;
            // Size of grid on axis X, in number of tiles
            int gridSizeX = 20;

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
            sf::Sprite currentHeroSprite;
            float currentHeroSpeed = 300.f;
            
            /// @brief Initialization
            void init();

        public:
            /// @brief Default constructor of Game class. Calls initialization function init().
            Game();

            // Methods

            /// @brief Shows character interactions as well as events on terminal
            void terminal();
            /// @brief Changes current hero
            void changeCurrentHero(Hero *newHero);
            /// SFML event handling
            void updateSFMLEvents();
            /// @brief Checks and resolves tile collisions
            sf::Vector2f tileCollision(const int tiles[], int tileNumber, int tileCollision, sf::Vector2f gridPosition, sf::Vector2f previousPos, sf::FloatRect rectBounds);
            /// @brief General updates
            void update();
            /// @brief Game render
            void render();
            /// @brief Runs game loop
            void run();

            /// @brief Deconstructor of Game class. Deletes all heros.
            virtual ~Game();
    };
}