#pragma once

#include <SDL.h>
#include <SDL_image.h>

#ifndef ndebug
#include "error.h"
#endif

#include <Cmath.h>

namespace chocco {
    class Renderer {
    private:
        SDL_Renderer* renderer;
        int flags;
    public:
        Renderer();
        Renderer(SDL_Window* window, int flags);
        ~Renderer();

        void clear();
        void present();

        void drawPoint(Vector2 pos, SDL_Color color);
        void drawLine(Vector2 coord1, Vector2 coord2, SDL_Color color);

        void drawRect(SDL_FRect rect, SDL_Color color, bool filled);
        void drawRect(SDL_FRect rect, SDL_Color color, double rotation, bool filled);
    };
}
