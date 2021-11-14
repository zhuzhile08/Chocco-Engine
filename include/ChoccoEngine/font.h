#pragma once

#ifndef ndebug
#include <iostream>
#endif

#include <Cmath.h>
#include <loaders.h>
#include <color.h>
#include <object.h>

#include <SDL.h>
#include <SDL_ttf.h>

namespace chocco {
	struct Font : public Object {
		std::string path, message;
		int size;
		SDL_Texture* texture;
		SDL_Color color;
		TTF_Font* font;
		Font(SDL_Renderer* renderer, std::string path, std::string name, SDL_Color color, Vector2 position, std::string message, int size);
		Font(SDL_Renderer* renderer, std::string path, std::string name, SDL_Color color, Vector2 position, std::string message, int size, bool style[4], int outline, bool hinting[3], bool renderStyle[2], SDL_Color = Color(0, 0, 0, 0));
		~Font();
	};
}
