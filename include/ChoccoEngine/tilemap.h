#pragma once

#ifndef ndebug
#include <iostream>
#endif

#include <vector>
#include <fstream>
#include <SDL.h>

#include <ChoccoEngine/Cmath.h>
#include <ChoccoEngine/loaders.h>

/**
 * Tilemaps
 * Tilemaps are just a sprite / a collection of sprites
 * If you want to make tilemaps, I would recomend you use this instead of normal sprites
 * This is a bit more efficient than to use the sprites
 * 
 * Has a function to load load the tile map folder (only .ctm files) and to create the tiles from it's base texture, which is loaded in the constructor
 * Also has a getter for the texture and the name
 **/

namespace chocco {
    class Tilemap {
    protected:
        SDL_Texture* baseTexture = nullptr, *texture = nullptr;
        std::vector <SDL_Rect> tiles;
        std::vector <std::vector <std::string>> tileData;
        std::string name = "tilemap";

        int clipSize, height, width;

        std::string loadFile(std::string path, int row);
    public:
        Tilemap();
        void destroy();

        void loadTileMap(std::string path, SDL_Renderer* renderer);
        void createTiles();

        std::string getName();
        SDL_Texture* getTexture();
    };
}
