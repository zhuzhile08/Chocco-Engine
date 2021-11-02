#include "loaders.h"

namespace ChoccoEngine {
	/**
	 * Since I have no idea how SDL_Color works, I just created this small thing that creates a color for me
	 * Has 4 values for the colors (a is for alpha)
	**/

	SDL_Color Color(int r, int g, int b, int a) {
		SDL_Color color;
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
		return color;
	}

	/**
	* Loading images using SDL_Image.
	* this can only load PNG images, because why would you need anything else
	**/

	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path) {
		SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

#ifndef ndebug
		if (texture == nullptr)
			std::cout << "SDL load texture error" << IMG_GetError << std::endl;
		return nullptr;
#endif
		return texture;
	}

	/**
	 * Loading textures with SDL_ttf
	 * I've heard that loading new textures everytime you need them is very inefficient, so please don't call this garbage everytime you need to render some text
	 * Instead, load every font you'll need in the constructor of a scene,
			which if far from as efficient as possible (for example loading every font you need at the start), but that is kinda too complicated for me
	*/

	TTF_Font* loadFont(std::string path, int size) {
		TTF_Font* font = TTF_OpenFont(path.c_str(), size);
#ifndef ndebug
		if (font == nullptr) {
			std::cout << "SDL load font error: " << TTF_GetError << std::endl;
			return nullptr;
		}
#endif
		return font;
	}
}
