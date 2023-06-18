#include "game/Interactable.h"

namespace He_ARC::rpg {
    // Methods

    /// @brief Checks whether player can interact with object or not.
    /// @param playerRect Player bounds.
    /// @return Whether object can be interacted with or not by the player.
    bool Interactable::canInteract(sf::FloatRect playerRect) {
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
    sf::Vector2f Interactable::tileCollision(sf::Vector2i gridPosition, sf::Vector2f previousPos, sf::FloatRect playerRect) {
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
    void Interactable::playSFX() {
        sfx.setBuffer(buffer);
        sfx.play();
    }
}