#pragma once
    
#include "Interactable.h"

namespace He_ARC::rpg {
    // Needed notes for music "puzzle"
    enum Notes { D, Eb, F, G };

    /**
    * Specific class for Interactables playing a note
    * @author Elisa Goloviatinski
    * @version 1.0
    */
    class MusicInteractable : virtual public Interactable {
        protected:
            Notes note;
        public:
            // Constructor

            /// @brief MusicInteractable standard parameterized constructor
            /// @param _gridX X-pos on map grid
            /// @param _gridY Y-pos on map grid
            /// @param _tileWidth Size of tile
            /// @param _soundfile Sfx associated to entity
            /// @param _note Associated note
            /// @param _collision Whether Entity object has collision or not
            MusicInteractable(int _gridX, int _gridY, int _tileWidth, string _soundfile, Notes _note, bool _collision = false) : Interactable(_gridX, _gridY, _tileWidth, _soundfile, _collision), note(_note) {}

            //Getter

            /// @brief Gets associated note to object
            /// @return Current associated note
            Notes getNote() const { return note; }

            //Setter

            /// @brief Changed associated note
            /// @param _note Note that's going to be associated with object
            void setNote(Notes _note) { note = _note; }
    };
}