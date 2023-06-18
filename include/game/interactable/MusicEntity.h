#pragma once

#include "Entity.h"
#include "MusicInteractable.h"

namespace He_ARC::rpg {
    /**
    * Specific class for entities playing a note
    * @author Elisa Goloviatinski
    * @version 1.0
    */
    class MusicEntity : public Entity, public MusicInteractable {
        public:
            // Constructor

            /// @param _collision Whether Entity object has collision or not
            /// @brief MusicEntity standard parameterized constructor
            /// @param _gridX X-pos on map grid
            /// @param _gridY Y-pos on map grid
            /// @param _tileWidth Size of tile
            /// @param _texturesrc Source of texture
            /// @param _soundfile Sfx associated to entity
            /// @param _note Associated note
            /// @param _collision Whether object has collisions or not
            MusicEntity(int _gridX, int _gridY, int _tileWidth, string _texturesrc, string _soundfile, Notes _note, bool _collision = false) : 
                MusicInteractable(_gridX, _gridY, _tileWidth, _soundfile, _note, _collision), 
                Entity(_gridX, _gridY, _tileWidth, _texturesrc, _soundfile, _collision), 
                Interactable(_gridX, _gridY, _tileWidth, _soundfile, _collision) {}
    };
}