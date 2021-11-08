#include "font.h"

namespace ChoccoEngine {
	/**
	 * Fonts using SDL_TTF
	 * they are just glorified sprites, nothing too interesting
	**/

	Font::Font(SDL_Renderer* renderer, std::string path, std::string name, SDL_Color color, Vector2 position, std::string message, int size)
		: path(path), size(size), message(message), Object(position, Vector2(1, 1), 0, name) {
	
		this->color = color;
		font = loadFont(path, size);
		SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
	#ifndef ndebug
		if (surface == nullptr){
			std::cout << "SDL font surface error: "<< SDL_GetError() << std::endl;
		}
	#endif

		texture = SDL_CreateTextureFromSurface(renderer, surface);

	#ifndef ndebug
		if (texture == nullptr){
			std::cout << "SDL font texture error: "<< SDL_GetError() << std::endl;
		}
	#endif
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
	}


	Font::Font(SDL_Renderer* renderer, std::string path, std::string name, SDL_Color color, Vector2 position, std::string message, int size, bool style[4], int outline, bool hinting[3], bool renderStyle[2], SDL_Color sColor)
		: path(path), size(size), message(message), Object(position, Vector2(1, 1), 0, name) {

		this->color = color;
		font = loadFont(path, size);
		SDL_Surface* surface;

		// huge if-statement block to make how the font looks like
		if (style[0]) TTF_SetFontStyle(font, TTF_STYLE_BOLD);
		if (style[1]) TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
		if (style[2]) TTF_SetFontStyle(font, TTF_STYLE_UNDERLINE);
		if (style[3]) TTF_SetFontStyle(font, TTF_STYLE_STRIKETHROUGH);
		if (!style[0] && !style[1] && !style[2] && !style[3])

		if (outline) TTF_SetFontOutline(font, outline);

		if (hinting[0]) TTF_SetFontHinting(font, TTF_HINTING_NORMAL);
		if (hinting[1]) TTF_SetFontHinting(font, TTF_HINTING_LIGHT);
		if (hinting[2]) TTF_SetFontHinting(font, TTF_STYLE_UNDERLINE);
		if (!hinting[0] && !hinting[1] && !hinting[2]) TTF_SetFontHinting(font, TTF_HINTING_NONE);

		if (renderStyle[0]) surface = TTF_RenderText_Shaded(font, message.c_str(), color, sColor);
		if (renderStyle[1]) surface = TTF_RenderText_Blended(font, message.c_str(), color);
		if (!renderStyle[0] && !renderStyle[1]) surface = TTF_RenderText_Solid(font, message.c_str(), color);

	#ifndef ndebug
		if (surface == nullptr){
			TTF_CloseFont(font);
			std::cout << "SDL font surface error: "<< SDL_GetError() << std::endl;
		}
	#endif

		texture = SDL_CreateTextureFromSurface(renderer, surface);

	#ifndef ndebug
		if (texture == nullptr){
			std::cout << "SDL font texture error: "<< SDL_GetError() << std::endl;
		}
	#endif
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
	}

	Font::~Font() {
		delete texture;
		TTF_CloseFont(font);
	}
}
