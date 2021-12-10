#pragma once

#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <gameVar.h>

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

#include <ChoccoEngine/sprite.h>
#include <ChoccoEngine/tilemap.h>
#include <ChoccoEngine/Cmath.h>
#include <ChoccoEngine/group.h>

/**
 * Renderer class
 * It's just basicly a class build ontop of the SDL renderer, nothing special
 * has some basic functions for loading and drawing textures -wip- and drawing some basic primitives
**/

namespace chocco {
    struct Renderer {
        SDL_Renderer* renderer;
        int flags;
        
        // some basic functions
        Renderer();
        Renderer(SDL_Window* window, int flags);

        void clear();
        void present();

        void destroy();

        // raw drawing functions
        void drawPoint(Vector2 pos, SDL_Color color);
        void drawLine(Vector2 coord1, Vector2 coord2, SDL_Color color);
        void drawRect(SDL_FRect rect, SDL_Color color, double rotation, bool filled);

        void drawSprite(Sprite sprite);
        void drawSpriteGroup(SpriteGroup group);

        void drawTilemap(Tilemap tilemap);
        void drawTileGroup(TileGroup group);

        // draw stuff to layers
        void drawPoint(Vector2 pos, SDL_Color color, SDL_Texture* layer);
        void drawLine(Vector2 coord1, Vector2 coord2, SDL_Color color, SDL_Texture* layer);
        void drawRect(SDL_FRect rect, SDL_Color color, double rotation, bool filled, SDL_Texture* layer);

        void drawSprite(Sprite sprite, SDL_Texture* layer);
        void drawSpriteGroup(SpriteGroup group, SDL_Texture* layer);

        void drawTilemap(Tilemap tilemap, SDL_Texture* layer);
        void drawTileGroup(TileGroup group, SDL_Texture* layer);

        void drawLayer(SDL_Texture* layer);
    };
}
