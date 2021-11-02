#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ChoccoEngine {
	SDL_Color Color(int r, int g, int b, int a);

	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);

	TTF_Font* loadFont(std::string path, int size);
}
