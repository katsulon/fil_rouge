#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tilemap.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <vector>
#include "hero/Hero.h"
#include "hero/class/ClassImpl.h"
#include "Interactable.h"
#include "interactable/InteractableImpl.h"
#include "DialogBox.h"

using namespace std;

namespace He_ARC::rpg {
    /**
    * @brief Class for game loop
    * @author Elisa Goloviatinski
    */
    class Game {
        private:
            // Attributes
            
            sf::RenderWindow window;
            sf::Image icon;
            sf::Vector2f size;
            sf::View view;
            sf::View guiView;
            float viewWidth;
            float viewHeight;
            float aspectRatio;
            sf::Event sfEvent;

            // Total elapsed time since execution

            sf::Clock clock;
            sf::Time deltaTotalTime;
            float totalTime;

            // Clock and time for sprite animation and movement

            sf::Clock deltaClock; //Elapsed time since the last frame was drawn
            sf::Time deltaTime;
            float time;

            // Create the tilemaps from the level definitions
            
            TileMap map;
            TileMap mapCliff;
            TileMap mapWater;
            TileMap mapBridge;
            TileMap mapStoneTilePlatform;
            TileMap mapStoneWallPlatform;
            TileMap mapStoneStairsPlatform;
            TileMap mapStonePlatformSequence;
            sf::Vector2i mapSize = sf::Vector2i(39,22);

            // View

            sf::Vector2f currentHeroPosReal;
            sf::Vector2f minViewSize;
            sf::Vector2f maxViewSize;

            int const frameRate = 60;
            // Var to check whether a key has already been pressed
            bool keyDown = false;

            // Dialog box

            DialogBox interactionDialog = DialogBox(sf::Vector2f(0, 0), "res/files/npcBeforeItem.txt");
            bool isGlobalEnabled = false;

            // Initialization of entities and related variables

            list<Interactable*> interactables;
            Entity bridgeSwitch = Entity(12, 13, 16*4, "res/sprites/map/forest/Rocks.png", "res/sfx/switch.wav", true);
            bool enableBridge = false;
            Entity obstacleText = Entity(17, 10, 16*4, "res/sprites/map/forest/Rocks.png");
            Interactable obstacle = Interactable(17, 11, 16*4, "res/sfx/destroy.wav", true);
            bool obstacleExists = true;
            Potion *ajaWine = new Potion(9999, "Aja Red Wine");
            Weapon *relicKey = new Weapon(9999, "Legendary Relic");
            Entity npcDemorden = Entity(18, 18, 16*4, "res/sprites/character/free_fighters/DEMORDEN/demorden.png", "res/sfx/coin.wav", true);
            bool transactionDone = false;
            Entity ladder = Entity(14, 0, 16*4, "res/sprites/map/forest/Cliff.png", "res/sfx/ladder.wav", false);
            bool onCliff = false;
            Entity chest = Entity(13, 5, 16*4, "res/sprites/map/chest/chest_closed.png", "res/sfx/chest.wav", true);
            bool chestOpen = false;

            // Music puzzle

            sf::Music musicCredits;

            const vector<Notes>noteSequence = {G, D, D, Eb, Eb, F, G, G, F, Eb};
            vector<Notes>inputNote;

            list<Entity*> stonePlatformEntities;
            Entity statueText = Entity(30, 0, 16*4, "res/sprites/map/forest/Environment_mod.png");
            Interactable statue = Interactable(30, 2, 16*4, true);

            vector<MusicInteractable*> noteLanterns;
            MusicEntity redNote = MusicEntity(28, 2, 16*4, "res/sprites/map/forest/Environment_mod.png", "res/sfx/notes/D.wav", D, true);
            Entity blueNoteText = Entity(29, 1, 16*4, "res/sprites/map/forest/Environment_mod.png");
            MusicInteractable blueNote = MusicInteractable(29, 2, 16*4, "res/sfx/notes/Eb.wav", Eb, true);
            Entity greenNoteText = Entity(31, 1, 16*4, "res/sprites/map/forest/Environment_mod.png");
            MusicInteractable greenNote = MusicInteractable(31, 2, 16*4, "res/sfx/notes/F.wav", F, true);
            MusicEntity yellowNote = MusicEntity(32, 2, 16*4, "res/sprites/map/forest/Environment_mod.png", "res/sfx/notes/G.wav", G, true);

            // Special bounds

            list<sf::FloatRect> tunnelBounds;
            
            // Initialization of party and hero

            list<Hero*> party;
            Warrior *war1 = new Warrior;
            Rogue *rog1 = new Rogue;
            Wizard *wzd1 = new Wizard;

            Hero *currentHero = war1;
            sf::Vector2f currentHeroPos = sf::Vector2f(0,7*16*4);
            // whether sprite is flipped or not
            bool currentHeroFlipped = false;
            sf::Vector2f currentHeroVelocity = sf::Vector2f(0, 0);
            sf::FloatRect playerBounds;
            
            /// @brief Initialization
            void init();

        public:
            /// @brief Default constructor of Game class. Calls initialization function init().
            Game();

            // Methods
            
            /// @brief Resizes current view according to aspect ratio.
            /// @param window Reference to window that's going to be resized as well as according to which the view is going to be resized
            /// @param view Reference to view that's going to be resized
            void resizeView(sf::RenderWindow &window, sf::View &view);
            
            /// @brief Shows character interactions as well as events on terminal.
            void terminal();

            /// @brief Changes current hero.
            void changeCurrentHero(Hero *newHero);

            /// @brief SFML event handling
            void updateSFMLEvents();

            /// @brief Checks and resolves tile collisions.
            /// @param tiles Array with tiles to check collision with
            /// @param tileNumber Current tilenumber in array according to current grid position
            /// @param nonColliderTile Tile where collision doesn't happen
            /// @param gridPosition Current entity grid position
            /// @param previousPos Previous entity position
            /// @param rectBounds Entity to check collision with
            /// @return Updated entity position to avoid collision
            sf::Vector2f tileCollision(const int tiles[], int tileNumber, int nonColliderTile, sf::Vector2i gridPosition, sf::Vector2f previousPos, sf::FloatRect rectBounds);

            /// @brief General updates.
            void update();

            /// @brief Game render.
            void render();

            /// @brief Runs game loop.
            void run();

            /// @brief Deconstructor of Game class. Deletes all heros.
            virtual ~Game();
    };
}