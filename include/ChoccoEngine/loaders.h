#pragma once

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

#include <string>
	
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace chocco {
	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);

	TTF_Font* loadFont(std::string path, int size);
}
