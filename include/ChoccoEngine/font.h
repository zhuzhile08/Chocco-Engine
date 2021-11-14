#pragma once

#ifndef ndebug
#include <iostream>
#endif

#include <Cmath.h>
#include <loaders.h>
#include <color.h>
#include <Sprite.h>

#include <SDL.h>
#include <SDL_ttf.h>

namespace chocco {
	class Font : public Sprite {
	private:
		std::string message;
		Sprite mask;
		SDL_Rect boundingBox;
		SDL_Color color, shadingColor = Color(0, 0, 0, 0);
		TTF_Font* font;
	public:
		Font();
		Font(std::string name, Vector2 position, Vector2 scale, double rotation);
		~Font();

		void determineStyle(bool style[4], int outline, bool hinting[3], bool renderStyle[2], SDL_Surface* surface);

		void draw();
	};
}
