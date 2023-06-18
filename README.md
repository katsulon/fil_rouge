# Fil Rouge

## Description
Mini project to apply concepts seen in class to an RPG written in C++.

Control 1 of 3 selectable characters in a small interactable minimap.
Follows a small scenario. When the final music starts playing that means the game is "over".
If something seems to sticks out, chances are there's something to do, generally by interacting with it.

If stuck here's the scenario:
- Enter tunnel
- Interact with trapdoor (might need to go further up in the tunnel if it doesn't seem to react)
- Get item from chest
- Activate bridge by interacting with the small rock
- Give item to npc who will give you an item to destroy the boulder blocking the way
- Look at color sequence given by stone lanterns below platform. Interact with the lanterns of the corresponding color in the given sequence. If the given sequence is correct, starts playing end music. Interact can be slightly too sensitive sometimes. If so, sequence can be reset with the key <kbd>R</kbd>.

## Commands
- <kbd>&#8592;</kbd><kbd>&#8593;</kbd><kbd>&#8595;</kbd><kbd>&#8594;</kbd>: Movement
- <kbd>E</kbd> or <kbd>Enter</kbd>: Interaction
- <kbd>R</kbd>: Reset note sequence
- <kbd>1</kbd>, <kbd>2</kbd> or <kbd>3</kbd>: Select Hero (in current state of game only cosmetic)
- <kbd>Esc</kbd>: Exit game

Screen can be resized to your heart's content so long as it's bigger than 800x600 (will automatically resize to 800x600 otherwise).

## Code features
- Character movement and animation. Movement handled by Game class while animation by Hero class.
- View movement that centers on the player in middle of screen. Stops being centered on hero if it hits edge of map.
- Tilemap imported from an SFML tutorial. Gives ability to draw tile by tile by delimiting 4 corners of a square.
- Collisions. If not an Interactable object, handled by Game class with the method Game::tileCollision. Otherwise method Interactable::tileCollision. Game::tileCollision checks whether next tile will be a collider and if so, sends back player to initial position. Interactable::tileCollision directly checks if player intersects with Interactable collider or not and if so sets player position to one of the sides of the collider depending on intersected side.
- Dynamic resizable screen. By using sf::View view and defining an aspectRatio variable it is possible to resize for any resolution. Just like for view movement, makes sure to not get out of the edge of the map. (cf. Game::resizeView)
- Dialog boxes. Need textfiles to display text. Can stay in same position according to screen and not map coordinates by using sf::View guiView rather than sf::View view.

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
- [x] Dialog boxes
- [ ] Slightly improved code
- [ ] Documentation

## Dependencies
- **CMake**: for building the project. Minimum version 3.14 required.
- **SFML 2.5.1**: multimedia API, used for graphics and audio

## Building the project
Inside the build folder, after creating it:

    cmake -DCMAKE_CXX_COMPILER=<location of c++ compiler> -DCMAKE_C_COMPILER=<location of c compiler> .. -G "MinGW Makefiles"
## Installing packages
If any of these don't work see [the official SFML tutorials](https://www.sfml-dev.org/tutorials/2.5/)
### Windows
CMakeLists have been configured to directly fetch the git repository of dependencies with FetchContent if the required built library was not found locally so normally dependencies should be integrated into build automatically. Just in case though, here are all the necessary dll files for runtime:
    
    openal32.dll
    sfml-audio-d-2.dll
    sfml-graphics-d-2.dll
    sfml-system-d-2.dll
    sfml-window-d-2.dll

### Linux
    sudo apt-get install libsfml-dev

## Possible future plan
- [ ] Improve code by either using keys or functions instead of ifs (possible scene class)

## Credits
### Additional art
- Warrior and Rogue: [Clumsy Medieval Dangerous 16x16](https://kevenece.itch.io/free-16x-pixel-art-fighters) asset pack by kevenece
- Map Tiles: [Forest Tileset](https://pixivan.itch.io/top-down-forest-tileset) by PixiVan
- Chest: [Chest (16x16) Open and closed](https://skalding.itch.io/chest-16x16-open-and-closed) by SkaldingDelight

### Additional sounds
- Open chest sfx: [8-Bit Sound Effects Library » Open_01.wav](https://freesound.org/people/LittleRobotSoundFactory/sounds/270338/) by LittleRobotSoundFactory
- Destroy obstacle sfx: [Earth Wind Fire Water pack 1 » Earth1.aif](https://freesound.org/people/pushtobreak/sounds/16793/) by pushtobreak
- NPC transaction sfx: [8-bit Video Game Sounds » Coins 1](https://freesound.org/people/ProjectsU012/sounds/341695/) by ProjectsU012
- Lantern keys sfx: [Pack: Piano FF](https://freesound.org/people/jobro/packs/2489/) by jobro