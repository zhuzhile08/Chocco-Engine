#pragma once

#include <map>
#include <SDL.h>
#include <SDL_image.h>

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

#include <ChoccoEngine/sprite.h>
#include <ChoccoEngine/Cmath.h>
#include <ChoccoEngine/spriteGroup.h>

/**
 * Renderer class
 * It's just basicly a class build ontop of the SDL renderer, nothing special
 * has some basic functions for loading and drawing textures -wip- and drawing some basic primitives
**/

namespace chocco {
    struct Renderer {
        SDL_Renderer* renderer;
        int flags;
        
        Renderer();
        Renderer(SDL_Window* window, int flags);
        // ~Renderer();

        void clear();
        void present();

        void destroy();

        void drawPoint(Vector2 pos, SDL_Color color);
        void drawLine(Vector2 coord1, Vector2 coord2, SDL_Color color);

        void drawRect(SDL_FRect rect, SDL_Color color, bool filled);
        void drawRect(SDL_FRect rect, SDL_Color color, double rotation, bool filled);

        void drawSprite(Sprite sprite);
        void drawSpriteGroup(SpriteGroup group);
    };
}
