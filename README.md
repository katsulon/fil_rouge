# Fil Rouge

## Description
Mini project to apply concepts seen in class to an RPG written in C++.

Follows a mini scenario. When the final music starts playing that means the game is "over".
If something seems to sticks out, chances are there's something to do, generally by interacting with it.

If stuck here's the scenario:
- Enter tunnel
- Interact with trapdoor (might need to go further up in the tunnel if it doesn't seem to react)
- Get item from chest
- Activate bridge by interacting with the small rock
- Give item to npc who will give you an item to destroy the boulder blocking the way
- Interact with statue to get a sequence of colors. Interact with the lanterns of the corresponding color in the given sequence. If the given sequence is correct, starts playing end music. Interact can be slightly too sensitive sometimes.

## Commands
- <kbd>&#8592;</kbd><kbd>&#8593;</kbd><kbd>&#8595;</kbd><kbd>&#8594;</kbd>: Movement
- <kbd>E</kbd> or <kbd>Enter</kbd>: Interaction
- <kbd>R</kbd> or <kbd>Enter</kbd>: Reset note sequence
- <kbd>1</kbd>, <kbd>2</kbd> or <kbd>3</kbd>: Select Hero (in current state of game only cosmetic)
- <kbd>Esc</kbd>: Exit game

Screen can be resized to your heart's content so long as it's bigger than 800x600 (will automatically resize to 800x600 otherwise).

## Project status
- [x] General setup
- [x] V1
- [x] V2
- [x] V3
- [x] V4
- [x] V5
- [x] Player movement
- [x] Game Map
- [x] Map Interaction
- [ ] Improve code
- [ ] Documentation

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
- [ ] Dialogue boxes
- [ ] Different game scenes
- [ ] Improve code by using keys or functions instead of ifs

## Credits
### Additional art
- Warrior and Rogue: [Clumsy Medieval Dangerous 16x16](https://kevenece.itch.io/free-16x-pixel-art-fighters) asset pack by kevenece
- Map Tiles: [Forest Tileset](https://pixivan.itch.io/top-down-forest-tileset) by PixiVan
- Chest: [Chest (16x16) Open and closed](https://skalding.itch.io/chest-16x16-open-and-closed) by SkaldingDelight

### Additional sounds
- Open chest sfx: [8-Bit Sound Effects Library » Open_01.wav](https://freesound.org/people/LittleRobotSoundFactory/sounds/270338/) by LittleRobotSoundFactory
- Destroy obstacle sfx: [Earth Wind Fire Water pack 1 » Earth1.aif](https://freesound.org/people/pushtobreak/sounds/16793/) by pushtobreak
- NPC transaction sfx: [8-bit Video Game Sounds » Coins 1](https://freesound.org/people/ProjectsU012/sounds/341695/) by ProjectsU012