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
        public:
            Interactable(int _gridX, int _gridY, int _tileWidth, bool _collision = false) : gridX(_gridX), gridY(_gridY), tileWidth(_tileWidth), collision(_collision) {
                interactionZone = sf::FloatRect((gridX-interactionRadius)*tileWidth,(gridY-interactionRadius)*tileWidth,3*tileWidth,3*tileWidth);
            }
            bool getCollision() const {
                return collision;
            }
            void setCollision(bool condition) {
                collision = condition;
            }
            
            bool canInteract(sf::FloatRect playerRect) {
                if (playerRect.left + playerRect.width + 1 >= interactionZone.left + playerRect.width
                && playerRect.left - playerRect.width - 1 <= interactionZone.left + playerRect.width
                && playerRect.top - playerRect.height - 1 <= interactionZone.top + playerRect.height
                && playerRect.top + playerRect.height + 1 >= interactionZone.top + playerRect.height) {
                    if (interactionZone.intersects(playerRect)) {
                        return true;
                    }
                }
                return false;
            }
            sf::Vector2f tileCollision(sf::Vector2f gridPosition, sf::Vector2f previousPos, sf::FloatRect playerRect) {
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
    };

    class Entity : public Interactable {
        private:
            string src;
            sf::Texture texture;
            sf::Sprite sprite;
        public:
            //Constructor
            Entity(int _gridX, int _gridY, int _tileWidth, string _src, bool _collision = false) : Interactable(_gridX, _gridY, _tileWidth, _collision), src(_src) {
                setTilePos(gridX, gridY);
                texture.loadFromFile(src);
                sprite.setTexture(texture);
                sprite.setScale(sf::Vector2f(4.0f, 4.0f));
            }
            // SFML Getters

            sf::Texture& getTexture() { return texture; }
            sf::Sprite getSprite() const { return sprite; }
            sf::Vector2f getPos() const { return sprite.getPosition(); }

            // SFML Setters
            void setSpriteTexture(sf::IntRect textureRect) { sprite.setTextureRect(textureRect); }
            void setPos(sf::Vector2f pos) { sprite.setPosition(pos); } 
            void setTilePos(int gridX, int gridY) {
                sf::Vector2f pos = sf::Vector2f(gridX*tileWidth, gridY*tileWidth);
                sprite.setPosition(pos);
            }
    };
}