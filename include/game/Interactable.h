#include <SFML/Graphics.hpp>
#include <iostream>

namespace He_ARC::rpg {
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

            /// @brief Checks whether player can interact with object or not.
            /// @param playerRect Player bounds.
            /// @return Whether object can be interacted with or not by the player.
            bool canInteract(sf::FloatRect playerRect) {
                return (playerRect.left + playerRect.width + 1 >= interactionZone.left + playerRect.width
                && playerRect.left - playerRect.width - 1 <= interactionZone.left + playerRect.width
                && playerRect.top - playerRect.height - 1 <= interactionZone.top + playerRect.height
                && playerRect.top + playerRect.height + 1 >= interactionZone.top + playerRect.height);
            }
            /// @brief Resolves collision with player.
            /// @param gridPosition Current player grid position.
            /// @param previousPos Previous player position.
            /// @param playerRect Player bounds to check collision with.
            /// @return Updated player position to avoid collision.
            sf::Vector2f tileCollision(sf::Vector2i gridPosition, sf::Vector2f previousPos, sf::FloatRect playerRect) {
                sf::Vector2f currentPos = previousPos;
                sf::FloatRect tileBounds = sf::FloatRect((gridX)*tileWidth,(gridY)*tileWidth,tileWidth,tileWidth);
                sf::FloatRect intersect;
                if (playerRect.intersects(tileBounds, intersect))
                {
                    if (intersect.width < intersect.height) {
                        if (playerRect.left < intersect.left) {
                            currentPos.x = tileBounds.left-playerRect.width;  
                        }
                        else {
                            currentPos.x = tileBounds.left+tileBounds.width;
                        }
                    }  
                    else {
                        if (playerRect.top < intersect.top) {
                            currentPos.y = tileBounds.top-playerRect.height;  
                        }
                        else {
                            currentPos.y = tileBounds.top+tileBounds.height;
                        }
                    }
                }
                return currentPos;  
            }
            /// @brief Plays sfx associated to entity
            void playSFX() {
                sfx.setBuffer(buffer);
                sfx.play();
            }
    };

    class Entity : public Interactable {
        private:
            string texturesrc;
            string soundfile;
            sf::Texture texture;
            sf::Sprite sprite;
        public:
            // Constructor

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
                sprite.setScale(sf::Vector2f(4.0f, 4.0f));
            }
            /// @brief Entity standard parameterized constructor with sfx
            /// @param _gridX X-pos on map grid
            /// @param _gridY Y-pos on map grid
            /// @param _tileWidth Size of tile
            /// @param _texturesrc Source of texture
            /// @param _soundfile Sfx associated to entity
            /// @param _collision Whether Entity object has collision or not
            Entity(int _gridX, int _gridY, int _tileWidth, string _texturesrc, string _soundfile, bool _collision = false) : Interactable(_gridX, _gridY, _tileWidth, _soundfile, _collision), texturesrc(_texturesrc){
                setTilePos(gridX, gridY);
                texture.loadFromFile(texturesrc);
                sprite.setTexture(texture);
                sprite.setScale(sf::Vector2f(4.0f, 4.0f));
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