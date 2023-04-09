#pragma once

#include <SFML/Graphics.hpp>
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
            //Variables
            sf::RenderWindow window;
            sf::Event sfEvent;
            sf::Clock deltaClock; //Elapsed time since the last frame was drawn
            sf::Image icon;
            
            //string const SPRITE_DIR = "res/sprites/"; currently useless

            int const frameRate = 60;
            //Var to check whether a key has already been pressed
            bool keyDown = false;
            
            list<Hero*> party;
            Warrior *war1 = new Warrior;
            Rogue *rog1 = new Rogue;
            Wizard *wzd1 = new Wizard;
            Necromancer *ncm1 = new Necromancer;
            // Initialization
            void init();

        public:
            /// Constructor of Game class
            Game();

            //Methods
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