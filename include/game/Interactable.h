#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

namespace He_ARC::rpg {
    /**
    * @brief Base class for interactables
    * @author Elisa Goloviatinski
    * @version 1.0
    */
    class Interactable {
        protected:
            bool collision = false;
            int gridX, gridY = 0;
            int tileWidth = 16;
            float interactionRadius = 1;
            sf::FloatRect interactionZone;
            sf::SoundBuffer buffer;
            sf::Sound sfx;
        public:
            // Constructor

            /// @brief Interactable standard parameterized constructor
            /// @param _gridX X-pos on map grid
            /// @param _gridY Y-pos on map grid
            /// @param _tileWidth Size of tile
            /// @param _collision Whether Interactable object has collision or not
            Interactable(int _gridX, int _gridY, int _tileWidth, bool _collision = false) : gridX(_gridX), gridY(_gridY), tileWidth(_tileWidth), collision(_collision) {
                interactionZone = sf::FloatRect((gridX-interactionRadius)*tileWidth,(gridY-interactionRadius)*tileWidth,3*tileWidth,3*tileWidth);
            }
            /// @brief Interactable standard parameterized constructor
            /// @param _gridX X-pos on map grid
            /// @param _gridY Y-pos on map grid
            /// @param _tileWidth Size of tile
            /// @param _soundfile Sfx associated to entity
            /// @param _collision Whether Interactable object has collision or not
            Interactable(int _gridX, int _gridY, int _tileWidth, string soundfile, bool _collision = false) : gridX(_gridX), gridY(_gridY), tileWidth(_tileWidth), collision(_collision) {
                interactionZone = sf::FloatRect((gridX-interactionRadius)*tileWidth,(gridY-interactionRadius)*tileWidth,3*tileWidth,3*tileWidth);
                buffer.loadFromFile(soundfile);
            }

            // Getter

            /// @brief Gets current collision state.
            /// @return Whether Interactable object has collision or not.
            bool getCollision() const {
                return collision;
            }

            // Setters

            /// @brief Changes loaded soundfile.
            /// @param src Source of soundfile.
            void setSoundfile(string src) {
                buffer.loadFromFile(src);
            }

            /// @brief Sets current collision state.
            /// @param condition Whether Interactable object is going to have collision or not.
            void setCollision(bool condition) {
                collision = condition;
            }
            
            // Methods

            bool canInteract(sf::FloatRect);
            sf::Vector2f tileCollision(sf::Vector2i, sf::Vector2f, sf::FloatRect);
            void playSFX();
    };
}