#pragma once

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <SDL.h>

#include <ChoccoEngine/Cmath.h>
#include <CHoccoEngine/loaders.h>

/**
 * Tilemaps
 * Tilemaps are just a sprite / a collection of sprites
 * If you want to make tilemaps, I would reccomend you use this instead of normal sprites
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
        std::vector <std::vector <std::string>> tiles;
        std::string name = "tilemap";

        int clipSize, length, width;
    public:
        Tilemap();
        Tilemap(SDL_Renderer* renderer, std::string path, int clipSize, std::string name);
        void destroy();

        void loadTileMap(std::string path);
        void createTiles();

        std::string getName();
        SDL_Texture* getTexture();
    };
}
