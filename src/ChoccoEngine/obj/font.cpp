#include <ChoccoEngine/font.h>

namespace chocco {
	/**
	 * Fonts using SDL_TTF
	 * they are just glorified sprites, nothing too interesting
	**/

	Font::Font(std::string name, Vector2 position, Vector2 scale, double rotation) : Sprite(name, position, scale, rotation){  }

	Font::~Font() {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		SDL_FreeSurface(baseSurface);
		baseSurface = nullptr;
		TTF_CloseFont(font);
		delete clip;
	}

	void Font::destroy() {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		SDL_FreeSurface(baseSurface);
		baseSurface = nullptr;
		TTF_CloseFont(font);
		delete clip;
	}

	// font initializers
	void Font::initFontSurface(SDL_Renderer* renderer, std::string path, SDL_Color color, int size, std::string message) {
		this->path = path;
		this->color = color;
		this->message = message;
		font = loadFont(path, size);
		baseSurface = TTF_RenderText_Solid(font, message.c_str(), color);
	#ifndef ndebug
		if (baseSurface == nullptr){
			SDLError("Font Surface init error");
		}
	#endif
	} 
	
	void Font::initFontTexture(SDL_Renderer* renderer) {
		texture = SDL_CreateTextureFromSurface(renderer, baseSurface);

	#ifndef ndebug
		if (texture == nullptr){
			SDLError("SDL font texture error");
		}
	#endif
		SDL_FreeSurface(baseSurface);
	}

	// function containing a huge if-statement block to make how the font looks like
	void Font::determineFontStyle(bool style[4], int outline, bool hinting[3], bool renderStyle[2]) {
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

		if (renderStyle[0]) baseSurface = TTF_RenderText_Shaded(font, message.c_str(), color, shadingColor);
		if (renderStyle[1]) baseSurface = TTF_RenderText_Blended(font, message.c_str(), color);
		if (!renderStyle[0] && !renderStyle[1]) baseSurface = TTF_RenderText_Solid(font, message.c_str(), color);
	}

	std::string Font::getMessage() {
		return message;
	}

	Vector2 Font::getBoundingBox() {
		return boundingBox;
	}
	
	SDL_Color Font::getColor() {
		return color;
	}

	SDL_Color Font::getShadingColor() {
		return shadingColor;
	}

}
