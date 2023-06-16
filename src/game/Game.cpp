#include "game/Game.h"

namespace He_ARC::rpg {
    // Initializer functions

    // Define the level with an array of tile indices (39x22)
    const int level[] =
    {
        120,120,120,134,10,132,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,
        120,120,120,134,10,132,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,
        120,120,120,134,10,132,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,34,34,34,34,34,34,34,34,34,34,34,34,120,34,34,34,34,
        120,120,120,134,10,132,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,
        120,120,120,134,10,132,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,
        120,120,120,134,10,132,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,121,122,122,122,122,122,123,10,10,10,121,122,122,122,122,122,122,
        155,155,155,156,10,154,123,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,35,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,145,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,35,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,145,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,35,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,145,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,35,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,27,28,10,10,288,145,137,138,120,120,120,137,155,138,120,120,120,120,120,120,120,35,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,49,50,10,10,144,170,171,170,155,155,155,171,223,154,122,122,122,122,122,122,122,57,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        220,221,222,144,144,289,144,144,144,286,287,288,144,144,144,144,144,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        264,265,266,144,10,10,10,10,10,144,144,144,144,144,144,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,144,144,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,144,144,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,144,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,144,144,144,144,144,144,144,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,10,10,144,220,221,222,144,144,144,144,144,144,144,144,144,144,144,10,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,10,144,144,242,243,244,144,144,144,144,144,144,144,144,144,144,144,144,10,10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,144,144,144,220,221,292,265,266,144,144,144,144,144,144,144,144,144,144,144,144,144,10,10,10,10,10,10,10,10,10,10,
    };
    const int levelCliff[] =
    {
        14,15,16,-1,-1,-1,14,15,15,15,15,15,15,15,15,15,15,15,15,15,15,20,35,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,37,
        14,15,16,-1,-1,-1,14,15,15,15,15,15,15,15,15,15,15,15,15,15,15,20,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
        14,15,16,-1,-1,-1,14,15,15,15,15,15,15,15,15,15,15,15,15,15,15,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        28,29,30,-1,-1,-1,28,29,15,15,15,15,15,15,15,15,15,15,15,15,15,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        42,43,44,-1,-1,-1,42,43,44,14,15,15,15,15,15,15,15,15,15,15,15,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        56,57,58,-1,-1,-1,56,57,58,14,15,15,15,15,15,15,15,15,15,15,15,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,4,5,15,15,15,15,15,15,15,15,15,15,15,15,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,28,15,15,15,16,42,43,44,14,15,15,15,15,15,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,42,44,28,29,30,56,57,58,28,29,29,29,29,29,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,56,58,42,43,44,-1,-1,-1,42,43,43,43,43,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,56,57,58,-1,-1,-1,56,57,57,57,57,57,58,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    };
    const int levelWater[] =
    {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,1,1,1,1,1,1,2,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12,12,12,12,12,12,12,13,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,28,12,12,12,12,12,12,12,27,1,2,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12,12,12,12,12,12,12,12,12,12,12,13,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,1,1,1,1,1,28,12,12,12,12,12,12,12,12,12,12,12,27,1,1,
        -1,-1,-1,-1,0,1,1,1,2,-1,-1,-1,-1,-1,-1,-1,0,28,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        -1,-1,-1,-1,11,12,12,12,27,1,1,1,1,1,1,1,28,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        -1,-1,-1,-1,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        -1,-1,-1,-1,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        1,1,1,1,28,12,12,12,12,12,12,12,12,12,12,12,12,16,23,23,23,23,23,23,23,23,17,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,16,23,23,23,23,23,23,24,-1,-1,-1,-1,-1,-1,-1,-1,22,23,17,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,17,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,16,23,23,23,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12,12,12,12,12,12,12,12,12,
    };
    const int stoneWallPlatform[] = {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,10,10,10,10,10,8,-1,-1,-1,8,10,10,10,10,10,10,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    };
    const int stoneTilePlatform[] = {
        33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
        33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
        -1,-1,-1,-1,-1,-1,-1,33,33,33,-1,-1,-1,-1,-1,-1,-1,
    };
    const int stairs[] = {
        4,5,6,
        11,12,13,
        18,19,20,
    };

    const int bridge[] = {
        25,26,27,
        32,33,34,
        32,33,34,
        32,33,34,
        32,33,34,
        32,33,34,
        39,40,41,
    };
    
    void Game::init() {
        window.create(sf::VideoMode(1280, 768), "Goloviatinski Fil Rouge");
        window.setFramerateLimit(frameRate);
    
        icon.loadFromFile("res/icon.png"); 
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        view = sf::View(sf::Vector2f(window.getSize().x/2, window.getSize().y/2), sf::Vector2f(window.getSize().x, window.getSize().y));
        viewWidth = view.getSize().x;
        viewHeight = view.getSize().y;
        view.setCenter(viewWidth/2, viewHeight/2);

        // loading tiles
        map.load("res/sprites/map/forest/Ground_Tileset.png", sf::Vector2u(16, 16), level, mapSize.x, mapSize.y);
        map.setScale(sf::Vector2f(4.0f, 4.0f));
        mapCliff.load("res/sprites/map/forest/Cliff.png", sf::Vector2u(16, 16), levelCliff, mapSize.x, mapSize.y);
        mapCliff.setScale(sf::Vector2f(4.0f, 4.0f));
        mapWater.load("res/sprites/map/forest/Water_Tileset.png", sf::Vector2u(16, 16), levelWater, mapSize.x, mapSize.y);
        mapWater.setScale(sf::Vector2f(4.0f, 4.0f));
        mapStoneTilePlatform.load("res/sprites/map/forest/Stairs_Bridge.png", sf::Vector2u(16, 16), stoneTilePlatform, 17, 3);
        mapStoneTilePlatform.setScale(sf::Vector2f(4.0f, 4.0f));
        mapStoneTilePlatform.setPosition(sf::Vector2f(22*16*4, 2*16*4));
        mapStoneStairsPlatform.load("res/sprites/map/forest/Stairs_Bridge.png", sf::Vector2u(16, 16), stairs, 3, 3);
        mapStoneStairsPlatform.setScale(sf::Vector2f(4.0f, 4.0f));
        mapStoneStairsPlatform.setPosition(sf::Vector2f(29*16*4, 4*16*4));
        mapStoneWallPlatform.load("res/sprites/map/forest/Environment.png", sf::Vector2u(16, 16), stoneWallPlatform, mapSize.x, mapSize.y);
        mapStoneWallPlatform.setScale(sf::Vector2f(4.0f, 4.0f));

        mapBridge.load("res/sprites/map/forest/Stairs_Bridge.png", sf::Vector2u(16, 16), bridge, 3, 7);
        mapBridge.setScale(sf::Vector2f(4.0f, 4.0f));
        mapBridge.setPosition(sf::Vector2f(13*16*4, 13*16*4));

        // loading entities
        bridgeSwitch.setSpriteTexture(sf::IntRect(16, 0, 16, 16));
        npcDemorden.setSpriteTexture(sf::IntRect(0,16, 16, 16));
        obstacleText.setSpriteTexture(sf::IntRect(0, 16*2, 16*2, 16*2));
        ladder.setSpriteTexture(sf::IntRect(16*11, 16*5, 16, 16));
        statueText.setSpriteTexture(sf::IntRect(0, 16*3, 16, 16*3));
        redNote.setSpriteTexture(sf::IntRect(16, 16*5, 16, 16));
        blueNoteText.setSpriteTexture(sf::IntRect(16*2, 16*3, 16, 16*2));
        greenNoteText.setSpriteTexture(sf::IntRect(16*3, 16*3, 16, 16*2));
        yellowNote.setSpriteTexture(sf::IntRect(16*4, 16*5, 16, 16));

        // entities list creation
        interactables.push_back(&bridgeSwitch);
        interactables.push_back(&chest);
        interactables.push_back(&npcDemorden);
        interactables.push_back(&obstacle);
        interactables.push_back(&statue);
        interactables.push_back(&redNote);
        interactables.push_back(&blueNote);
        interactables.push_back(&greenNote);
        interactables.push_back(&yellowNote);

        // stone platform entities
        stonePlatformEntities.push_back(&redNote);
        stonePlatformEntities.push_back(&blueNoteText);
        stonePlatformEntities.push_back(&statueText);
        stonePlatformEntities.push_back(&greenNoteText);
        stonePlatformEntities.push_back(&yellowNote);

        // party creation
        party.push_back(war1);
        party.push_back(rog1);
        party.push_back(wzd1);
        party.push_back(ncm1);

        // tunnel bounds creation
        tunnelBounds.push_back(sf::FloatRect(7*16*4, 6*16*4, 4*16*4, 16*4));
        tunnelBounds.push_back(sf::FloatRect(10*16*4, 2*16*4, 16*4, 5*16*4));
        tunnelBounds.push_back(sf::FloatRect(10*16*4, 2*16*4, 5*16*4, 16*4));
        tunnelBounds.push_back(sf::FloatRect(14*16*4, 0*16*4, 16*4, 3*16*4));


        for(Hero *member : party) {
            member->currentState=Hero::Immobile;
            member->loadTexture(frameRate, member->getSpriteState());
        }

        currentHero->setSpriteState(currentHeroFlipped);
        currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
    }

    // Constructors

    Game::Game() {
        init();
    }

    void Game::resizeView(sf::RenderWindow &window, sf::View &view) {
        size = sf::Vector2f(window.getSize());
        // Sets min window size
        if (size.x < 800) {
            size.x = 800;
        }
        if (size.y < 600) {
            size.y = 600;
        }
        window.setSize(sf::Vector2u(size));
        aspectRatio = size.x/size.y;
        if (minViewSize.x >= 0) {
            currentHeroPos.x = aspectRatio*viewHeight/2;
        }
        if (currentHeroPos.x-currentHero->getFrameSize()*4-16/2*4 + size.x/2 >= maxViewSize.x) {
            currentHeroPos.x = mapSize.x*4*16-aspectRatio*viewHeight/2;
        }
        if (minViewSize.y >= 0) {
            currentHeroPos.y = viewHeight/2;
        }
        if (currentHeroPos.y-currentHero->getFrameSize()*4-16/2*4 + size.y/2 >= maxViewSize.y) {
            currentHeroPos.y = mapSize.y*4*16-viewHeight/2;
        }
        view.setCenter(currentHeroPos);
        view.setSize(sf::Vector2f(aspectRatio*viewHeight, viewHeight));
        window.setView(sf::View(view));
    }

    void Game::terminal() {
        for(const Hero *member : party) {
            cout << *member;
        }

        war1->interact(*wzd1);
        wzd1->interact(*ncm1);
        rog1->interact(*wzd1);

        wzd1->castSpell();
        ncm1->castSpell();
        ncm1->raiseUndeads();

        cout << "Staff damage: " << wzd1->getWeapon().getFeature() << endl;
        cout << wzd1->getLeftHandItem()->getName() << endl;
        cout << ncm1->getLeftHandItem()->getName() << endl;

        Weapon *wpn1 = new Weapon();
        war1->backpack.pack(wpn1);
        Weapon *wpn2 = new Weapon(20, "Nice Bass");
        war1->backpack.pack(wpn2);
        Weapon *wpn3 = new Weapon(5, "Stick");
        war1->backpack.pack(wpn3);
        Shield *shd1 = new Shield();
        war1->backpack.pack(shd1);
        Shield *shd2 = new Shield(1000, "Stovetop");
        war1->backpack.pack(shd2);
        Potion *pot1 = new Potion();
        war1->backpack.pack(pot1);
        Potion *pot2 = new Potion(1000, "Super extra wonderful delicious elixir");
        war1->backpack.pack(pot2);
        
        while (war1->backpack.isNotEmpty()) {
            delete war1->backpack.unPack();
        }
    }

    void Game::changeCurrentHero(Hero *newHero) {
        currentHeroFlipped = currentHero->getSpriteState();
        currentHeroPos = currentHero->getPos();
        currentHero = newHero;
        currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
        currentHero->setSpriteState(currentHeroFlipped);
    }

    void Game::updateSFMLEvents() {
        deltaTime = deltaClock.restart();
        time = deltaTime.asSeconds();
        currentHeroVelocity = sf::Vector2f(0, 0);
        // Player movement 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            currentHeroVelocity.x = 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            currentHeroVelocity.x = -1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            currentHeroVelocity.y = -1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            currentHeroVelocity.y = 1.f;
        }
        currentHero->walk(time, currentHeroVelocity.x, currentHeroVelocity.y, frameRate);
        currentHeroFlipped = currentHero->getSpriteState();
        while (window.pollEvent(sfEvent)) {
            switch (sfEvent.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resizeView(window, view);
                    break;
                case sf::Event::KeyPressed:
                    if(sfEvent.key.code == sf::Keyboard::Escape)
                        window.close();
                    if (keyDown == false) {
                        // Interactions
                        if (bridgeSwitch.canInteract(playerBounds)) {
                            if(sfEvent.key.code == sf::Keyboard::Enter || sfEvent.key.code == sf::Keyboard::E) {
                                bridgeSwitch.playSFX();
                                enableBridge = true;
                                keyDown = true;
                            }
                        }
                        if (ladder.canInteract(playerBounds)) {
                            if(sfEvent.key.code == sf::Keyboard::Enter || sfEvent.key.code == sf::Keyboard::E) {
                                onCliff = !onCliff;
                                ladder.playSFX();
                                keyDown = true;
                            }
                        }
                        if (chest.canInteract(playerBounds) && chestOpen == false) {
                            if(sfEvent.key.code == sf::Keyboard::Enter || sfEvent.key.code == sf::Keyboard::E) {
                                war1->backpack.pack(ajaWine);
                                chest.playSFX();
                                chestOpen = true;
                                keyDown = true;
                            }
                        }
                        if (npcDemorden.canInteract(playerBounds) && transactionDone == false) {
                            if((sfEvent.key.code == sf::Keyboard::Enter || sfEvent.key.code == sf::Keyboard::E)
                            && war1->backpack.getStackTop() == ajaWine) {
                                war1->backpack.unPack();
                                war1->backpack.pack(relicKey);
                                npcDemorden.playSFX();
                                transactionDone = true;
                                keyDown = true;
                            }
                        }
                        if (obstacle.canInteract(playerBounds)) {
                            if((sfEvent.key.code == sf::Keyboard::Enter || sfEvent.key.code == sf::Keyboard::E)
                            && war1->backpack.getStackTop() == relicKey) {
                                obstacle.playSFX();
                                obstacleExists = false;
                                war1->backpack.unPack();
                                interactables.remove(&obstacle);
                                keyDown = true;
                            }
                        }
                        // Prints hero methods result on terminal
                        if(sfEvent.key.code == sf::Keyboard::P) {
                            terminal();
                            keyDown = true;
                        }
                        // Hero selection management
                        if (sfEvent.key.code == sf::Keyboard::Num1)
                        {
                            changeCurrentHero(war1);
                            keyDown = true;
                        }
                        if (sfEvent.key.code == sf::Keyboard::Num2)
                        {
                            changeCurrentHero(rog1);
                            keyDown = true;
                        }
                        if (sfEvent.key.code == sf::Keyboard::Num3)
                        {
                            changeCurrentHero(wzd1);
                            keyDown = true;
                        }
                        
                    }
                    break;
                case sf::Event::KeyReleased:
                    keyDown = false;
                    currentHero->currentState=Hero::Immobile;
                    break;
            }
        }
    }

    sf::Vector2f Game::tileCollision(const int levelTiles[], int nonColliderTile, int tileNumber, sf::Vector2i gridPosition, sf::Vector2f previousPos, sf::FloatRect rectBounds) {
        sf::Vector2f currentPos = previousPos;
        sf::FloatRect tileBounds = sf::FloatRect((gridPosition.x+1)*16*4,(gridPosition.y)*16*4,16*4,16*4);
        if (levelTiles[tileNumber+1] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.x = tileBounds.left-rectBounds.width;  
            }
        }
        tileBounds = sf::FloatRect((gridPosition.x)*16*4,(gridPosition.y+1)*16*4,16*4,16*4);
        if (levelTiles[tileNumber+mapSize.x] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.y = tileBounds.top-rectBounds.height;
            }
        }    
        tileBounds = sf::FloatRect((gridPosition.x-1)*16*4,(gridPosition.y)*16*4,16*4,16*4);
        if (levelTiles[tileNumber-1] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.x = tileBounds.left+tileBounds.width;
            }
        }        
        tileBounds = sf::FloatRect((gridPosition.x)*16*4,(gridPosition.y-1)*16*4,16*4,16*4);
        if (levelTiles[tileNumber-mapSize.x] != nonColliderTile) {
            if (rectBounds.intersects(tileBounds))
            {
                currentPos.y = tileBounds.top+tileBounds.height;
            }
        }
        return currentPos;       
    }

    void Game::update() {
        updateSFMLEvents();
        view = window.getView();
        currentHeroPos = currentHero->getPos();
        // Collision management
        bool collisionEnabled = true;
        playerBounds = sf::FloatRect(currentHeroPos.x, currentHeroPos.y, 16*4,16*4);
        sf::Vector2i playerGridPosition = sf::Vector2i(0,0);
        playerGridPosition.x = round(playerBounds.left / (16*4));
        playerGridPosition.y = round(playerBounds.top / (16*4));
        int tileNumber = (playerGridPosition.y * mapSize.x + playerGridPosition.x);
        // Bridge river collision removal
        sf::FloatRect bridgeBounds = sf::FloatRect(14*16*4, 14*16*4, 16*4, 16*4*5);
        sf::FloatRect intersect;
        if (playerBounds.intersects(bridgeBounds) && enableBridge) {
            collisionEnabled = false;
            if (playerBounds.intersects(bridgeBounds, intersect)) {
                if (intersect.width < intersect.height) {
                    currentHeroPos.x = bridgeBounds.left;  
                }  
            }
        }
        // Tunnel cliff collision removal
        if (!onCliff) {
            for(sf::FloatRect bounds : tunnelBounds) {
                if (playerBounds.intersects(bounds)) {
                    collisionEnabled = false;
                    if (playerBounds.intersects(bounds, intersect)) {
                        if (playerGridPosition.x < 10 || (playerGridPosition.x < 14 && playerGridPosition.x > 10)) {
                            if (intersect.height < intersect.width) {
                                currentHeroPos.y = bounds.top; 
                            }   
                        }
                        else if (playerGridPosition == sf::Vector2i(10,6) || playerGridPosition == sf::Vector2i(14,2)) {
                            if (playerBounds.left+playerBounds.width > bounds.left + bounds.width) {
                                currentHeroPos.x = bounds.left+bounds.width-playerBounds.width;  
                            }
                            if (playerBounds.top + playerBounds.height > bounds.top + bounds.height) {
                                currentHeroPos.y  = bounds.top+bounds.height-playerBounds.height; 
                            }

                        }
                        else if (playerGridPosition == sf::Vector2i(10,2)) {
                            if (playerBounds.left < bounds.left) {
                                currentHeroPos.x = bounds.left;  
                            }
                            if (playerBounds.top < bounds.top) {
                                currentHeroPos.y  = bounds.top; 
                            }

                        }
                        else if (playerGridPosition.x == 10 || playerGridPosition.x == 14) {
                            if (intersect.width < intersect.height) {
                                currentHeroPos.x = bounds.left;  
                            }  
                        }
                    }
                }
            }
        }
        else { // On cliff scene
            collisionEnabled = false;
            currentHeroPos = tileCollision(levelCliff, 15, tileNumber, playerGridPosition, currentHeroPos, playerBounds);
            if (chest.getCollision()) {
                currentHeroPos = chest.tileCollision(playerGridPosition, currentHeroPos, playerBounds);
            }
        }
        // Default scene
        if (collisionEnabled) {
            currentHeroPos = tileCollision(levelWater, -1, tileNumber, playerGridPosition, currentHeroPos, playerBounds);
            currentHeroPos = tileCollision(levelCliff, -1, tileNumber, playerGridPosition, currentHeroPos, playerBounds);
            currentHeroPos = tileCollision(stoneWallPlatform, -1, tileNumber, playerGridPosition, currentHeroPos, playerBounds);

            for (Interactable *interactable : interactables) {
                if (interactable->getCollision()) {
                    currentHeroPos = interactable->tileCollision(playerGridPosition, currentHeroPos, playerBounds);
                }
            }
        }

        // Checks for collision on left side of map
        if (currentHero->getPos().x < 0.f){
            currentHeroPos.x = 0.f;
        }
        // Checks for collision on right side of map
        if ((currentHero->getPos().x+currentHero->getFrameSize()+currentHero->getFrameSize()/2) > mapSize.x*16*4) {
            currentHeroPos.x = mapSize.x*16*4-currentHero->getFrameSize()-currentHero->getFrameSize()/2;
        }
        // Checks for collision on top of map
        if (currentHero->getPos().y < 0.f) {
            currentHeroPos.y = 0.f;
        }
        // Checks for collision on bottom of map
        if ((currentHero->getPos().y+currentHero->getFrameSize()+currentHero->getFrameSize()/2) > mapSize.y*16*4 ) {
            currentHeroPos.y = mapSize.y*16*4 - currentHero->getFrameSize()-currentHero->getFrameSize()/2;
        }

        // View movement
        currentHeroPosReal = sf::Vector2f(window.mapCoordsToPixel(currentHeroPos));
        minViewSize = sf::Vector2f(window.mapCoordsToPixel(sf::Vector2f(0,0)));
        maxViewSize = sf::Vector2f(window.mapCoordsToPixel(sf::Vector2f(mapSize.x*16*4,mapSize.y*16*4)));
        sf::Vector2f viewMoveSpeed = sf::Vector2f(0.f, 0.f);
        if (((currentHeroPosReal.x+16/2*4-window.getSize().x/2) < 0) && (minViewSize.x < 0) && currentHeroVelocity.x < 0) {
            viewMoveSpeed.x = (currentHeroPos.x-view.getCenter().x)*time;
        }
        if (((currentHeroPosReal.x+16/2*4+window.getSize().x/2) > window.getSize().x) && (maxViewSize.x > window.getSize().x) && currentHeroVelocity.x > 0) {
            viewMoveSpeed.x = ((currentHeroPos.x+16/2*4*2)-view.getCenter().x)*time;
        }
        if (((currentHeroPosReal.y+16/2*4-window.getSize().y/2) < 0) && (minViewSize.y < 0) && currentHeroVelocity.y < 0) {
            viewMoveSpeed.y = (currentHeroPos.y-view.getCenter().y)*time;
        }
        if (((currentHeroPosReal.y+16/2*4+window.getSize().y/2) > window.getSize().y) && (maxViewSize.y > window.getSize().y) && currentHeroVelocity.y > 0) {
            viewMoveSpeed.y = ((currentHeroPos.y+16/2*4*2)-view.getCenter().y)*time;
        }
        
        viewMoveSpeed*=currentHero->getSpeed()*2/100;
        view.move(viewMoveSpeed);
        window.setView(view);

        currentHero->setPos(currentHeroPos.x, currentHeroPos.y);
        // Log file
        deltaTotalTime = clock.getElapsedTime();
        totalTime = deltaTotalTime.asSeconds();
        ofstream log("log.txt");
        log << "Player coordinates: (" << currentHeroPos.x << ", " << currentHeroPos.y << ")\n";
        log << "Player grid coordinates: (" << playerGridPosition.x << ", " << playerGridPosition.y << ")\n";
        log << "Player screen coordinates: (" << currentHeroPosReal.x << ", " << currentHeroPosReal.y << ")\n";
        log << "Current top item in backpack: " << (war1->backpack.isNotEmpty()? war1->backpack.getStackTop()->getName() : "None") << endl;
        log << "Elapsed time in seconds since execution: " << totalTime << endl;
        log.close();
        // Loading textures
        currentHero->loadTexture(frameRate, currentHeroFlipped);
        if (chestOpen) {
            chest.setTexture("res/sprites/map/chest/chest_open.png");
        }
        
    }

    void Game::render() {
        window.clear();

        // White rectangle for debug
        /*sf::RectangleShape test;
        test.setSize(sf::Vector2f(16*4,16*4));
        test.setPosition(currentHero->getPos().x,currentHero->getPos().y);
        test.setFillColor(sf::Color::Transparent);
        test.setOutlineColor(sf::Color::White);
        test.setOutlineThickness(1.f);
        window.draw(test);*/
        // Render items
        window.draw(map);
        window.draw(mapWater);
        window.draw(npcDemorden.getSprite());
        window.draw(mapStoneTilePlatform);
        window.draw(mapStoneWallPlatform);
        window.draw(mapStoneStairsPlatform);

        window.draw(bridgeSwitch.getSprite());
        if (enableBridge) {
            window.draw(mapBridge);
        }

        if (onCliff) {
            window.draw(mapCliff);
            window.draw(ladder.getSprite());
            window.draw(chest.getSprite());
            window.draw(currentHero->getSprite());
        }
        else {
            window.draw(currentHero->getSprite());
            window.draw(mapCliff);
            window.draw(ladder.getSprite());
            window.draw(chest.getSprite());
        }

        if (obstacleExists) {
            window.draw(obstacleText.getSprite());
        }

        for (Entity *entity : stonePlatformEntities) {
            window.draw(entity->getSprite());
        }

        window.display();
    }

    void Game::run() {
        while (window.isOpen()) {
            update();
            render();
        }
    }

    // Destructors
    Game::~Game() {
        for(Hero *member : party) {
            delete member;
        }
    }
}