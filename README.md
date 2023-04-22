# Fil Rouge

## Description
Mini project to apply concepts seen in class to an RPG written in C++.

## Project status
- [x] General setup
- [x] V1
- [x] V2
- [x] V3
- [x] V4
- [ ] V5
- [ ] Additional features?

## Dependencies
- **CMake**: for building the project. Minimum version 3.14 required.
- **SFML 2.5.1**: multimedia API, used for graphics

## Building the project
    cmake -DCMAKE_CXX_COMPILER=<location of c++ compiler> -DCMAKE_C_COMPILER=<location of c compiler> .. -G "MinGW Makefiles"
## Installing packages
If any of these don't work see [the official SFML tutorials](https://www.sfml-dev.org/tutorials/2.5/)
### Windows
CMakeLists have been configured to directly fetch the git repository of dependencies with FetchContent if the required built library was not found locally so normally dependencies should be integrated into build automatically.
### Linux
    sudo apt-get install libsfml-dev

## Possible future plan
- Sprite Movement
- Game Map
- Dialogue Tree/Interaction (Trading/combat system?)

## Credits
### Additional art
- Warrior and Rogue: Clumsy Medieval Dangerous 16x16 asset pack by kevenece