#include <ChoccoEngine/loaders.h>

namespace chocco {
	/**
	* Loading images using SDL_Image.
	* this can only load PNG images, because why would you need anything else
	**/

	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path) {
		SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

#ifndef ndebug
		if (texture == nullptr)
			SDLError("SDL load texture error");

		return nullptr;
#endif
		return texture;
	}

	/**
	 * Loading fonts with SDL_ttf
	 * I've heard that loading new fonts everytime you need them is very inefficient, so please don't call this garbage everytime you need to render some text
	 * Instead, load every font you'll need in the constructor of a scene,
			which if far from as efficient as possible (for example loading every font you need at the start), but that is kinda too complicated for me
	*/

	TTF_Font* loadFont(std::string path, int size) {
		TTF_Font* font = TTF_OpenFont(path.c_str(), size);
#ifndef ndebug
		if (font == nullptr) {
			TTFError("Load Font error");
			return nullptr;
		}
#endif
		return font;
	}
}
