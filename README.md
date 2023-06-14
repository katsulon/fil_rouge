# Fil Rouge

## Description
Mini project to apply concepts seen in class to an RPG written in C++.

## Commands
- <kbd>&#8592;</kbd><kbd>&#8593;</kbd><kbd>&#8595;</kbd><kbd>&#8594;</kbd>: Movement
- <kbd>E</kbd> or <kbd>Enter</kbd>: Interaction
- <kbd>1</kbd>, <kbd>2</kbd> or <kbd>3</kbd>: Select Hero
- <kbd>Esc</kbd>: Exit game

## Project status
- [x] General setup
- [x] V1
- [x] V2
- [x] V3
- [x] V4
- [x] V5
- [x] Player movement
- [x] Game Map
- [ ] Map Interaction

## Dependencies
- **CMake**: for building the project. Minimum version 3.14 required.
- **SFML 2.5.1**: multimedia API, used for graphics

## Building the project
Inside the build folder, after creating it:

    cmake -DCMAKE_CXX_COMPILER=<location of c++ compiler> -DCMAKE_C_COMPILER=<location of c compiler> .. -G "MinGW Makefiles"
## Installing packages
If any of these don't work see [the official SFML tutorials](https://www.sfml-dev.org/tutorials/2.5/)
### Windows
CMakeLists have been configured to directly fetch the git repository of dependencies with FetchContent if the required built library was not found locally so normally dependencies should be integrated into build automatically.
### Linux
    sudo apt-get install libsfml-dev

## Possible future plan
- [ ] Dialogue Tree (Trading/combat system?)
- [ ] Different game scenes

## Credits
### Additional art
- Warrior and Rogue: [Clumsy Medieval Dangerous 16x16](https://kevenece.itch.io/free-16x-pixel-art-fighters) asset pack by kevenece
- Map Tiles: [Forest Tileset](https://pixivan.itch.io/top-down-forest-tileset) by PixiVan
- Chest: [Chest (16x16) Open and closed](https://skalding.itch.io/chest-16x16-open-and-closed) by SkaldingDelight