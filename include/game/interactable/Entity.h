#pragma once

#include "game/Interactable.h"

namespace He_ARC::rpg {
/**
    * @brief Base class for entities. Derived from Interactable but includes textures and sfx
    * @author Elisa Goloviatinski
    * @version 1.0
    */
    class Entity : virtual public Interactable {
        protected:
            const float SCALE = 4.0f;
            string texturesrc;
            string soundfile;
            sf::Texture texture;
            sf::Sprite sprite;
        public:
            // Constructors

            /// @brief Entity standard parameterized constructor
            /// @param _gridX X-pos on map grid
            /// @param _gridY Y-pos on map grid
            /// @param _tileWidth Size of tile
            /// @param _texturesrc Source of texture
            /// @param _collision Whether Entity object has collision or not
            Entity(int _gridX, int _gridY, int _tileWidth, string _texturesrc, bool _collision = false) : Interactable(_gridX, _gridY, _tileWidth, _collision), texturesrc(_texturesrc) {
                setTilePos(gridX, gridY);
                texture.loadFromFile(texturesrc);
                sprite.setTexture(texture);
                sprite.setScale(sf::Vector2f(SCALE, SCALE));
            }
            /// @brief Entity standard parameterized constructor with sfx
            /// @param _gridX X-pos on map grid
            /// @param _gridY Y-pos on map grid
            /// @param _tileWidth Size of tile
            /// @param _texturesrc Source of texture
            /// @param _soundfile Sfx associated to entity
            /// @param _collision Whether object has collisions or not
            Entity(int _gridX, int _gridY, int _tileWidth, string _texturesrc, string _soundfile, bool _collision = false) : Interactable(_gridX, _gridY, _tileWidth, _soundfile, _collision), texturesrc(_texturesrc){
                setTilePos(gridX, gridY);
                texture.loadFromFile(texturesrc);
                sprite.setTexture(texture);
                sprite.setScale(sf::Vector2f(SCALE, SCALE));
            }
            // SFML Getters

            /// @brief Gets current texture.
            /// @return Current loaded texture.
            sf::Texture& getTexture() { return texture; }
            /// @brief Gets current sprite
            /// @return Current sprite
            sf::Sprite getSprite() const { return sprite; }
            /// @brief Gets current position in float coordinates.
            /// @return Current position.
            sf::Vector2f getPos() const { return sprite.getPosition(); }

            // SFML Setters

            /// @brief Sets texture to use for sprite
            /// @param src Source of texture
            void setTexture(string src) { texture.loadFromFile(src); }
            /// @brief Sets part of texture to use for sprite.
            /// @param textureRect Size of cut texture.
            void setSpriteTexture(sf::IntRect textureRect) { sprite.setTextureRect(textureRect); }
            /// @brief Sets new position in float coordinates.
            /// @param pos New position to set.
            void setPos(sf::Vector2f pos) { sprite.setPosition(pos); } 
            /// @brief Sets new position in grid coordinates.
            /// @param gridX X-pos on map grid.
            /// @param gridY Y-pos on map grid.
            void setTilePos(int gridX, int gridY) {
                sf::Vector2f pos = sf::Vector2f(gridX*tileWidth, gridY*tileWidth);
                sprite.setPosition(pos);
            }
    };
}