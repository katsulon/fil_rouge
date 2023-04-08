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
- **CMake**: for building the project. Minimum version 3.12 required.
- **ImGui-SFML v2.5**: Binds Dear ImGui to SFML. It therefore itself has the following dependencies:
    - **SFML >= 2.5.0**: multimedia API, used for graphics
    - **Dear ImGui >= 1.80**: GUI library

CMakeLists have been configured to directly fetch the git repository of dependencies with FetchContent so normally dependencies should be integrated into build automatically.

## Possible future plan
- Sprite Movement
- Game Map
- Dialogue Tree/Interaction (Trading/combat system?)
- ImGui for menus

## Credits
### Additional art
- Warrior and Rogue: Clumsy Medieval Dangerous 16x16 asset pack by kevenece