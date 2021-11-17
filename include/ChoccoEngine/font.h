#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include <ChoccoEngine/Cmath.h>
#include <ChoccoEngine/loaders.h>
#include <ChoccoEngine/color.h>
#include <ChoccoEngine/sprite.h>
#include <ChoccoEngine/renderer.h>

#ifndef ndebug
#include <error.h>
#endif

/**
 * Font file
 * Has 2 classes: FontMask and the Font itself
 * 
 * The Fontmask /wip/ is a Thing that you can use to cover up font and let them appear gradually contains ...
 * 
 * The Font class is just a Sprite, that loads Fonts instead of images.
 * Everything is prety self explainatory in there
 * The bounding box is a box like thing that keeps the on screen text under a certain length. -1 tit the default value
**/

namespace chocco {
	class FontMask : public Sprite {

	};

	class Font : public Sprite {
	protected:
		std::string message = "default";
		Vector2 boundingBox = {-1, -1};
		FontMask mask;
		SDL_Surface* baseSurface = nullptr;
		SDL_Color color, shadingColor = Color(0, 0, 0, 0);
		TTF_Font* font = nullptr;

	public:
		Font();
		Font(std::string name, Vector2 position, Vector2 scale, double rotation);
		~Font();

		void destroy();

		void initFontSurface(Renderer renderer, std::string path, SDL_Color color, int size, std::string message);
		void determineFontStyle(bool style[4], int outline, bool hinting[3], bool renderStyle[2]);
		void initFontTexture(Renderer renderer);
		void initFontAttributes(Vector2 boundingBox);

		std::string getMessage();
		Vector2 getBoundingBox();
		SDL_Color getColor();
		SDL_Color getShadingColor();
	};
}
