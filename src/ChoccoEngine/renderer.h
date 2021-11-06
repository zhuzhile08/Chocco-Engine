#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "util/error.h"
#include "util/math.h"

namespace ChoccoEngine {
    class Renderer {
    private:
        SDL_Renderer* renderer;
        int flags;
    public:
        Renderer();
        Renderer(SDL_Window* window, int flags);
        ~Renderer();

        void drawPoint(Vector2 pos, SDL_Color color);
        void drawLine(Vector2 coord1, Vector2 coord2, SDL_Color color);

        void drawRect(SDL_FRect rect, SDL_Color color, bool filled);
        void drawRect(SDL_FRect rect, SDL_Color color, double rotation, bool filled);
    };
}
