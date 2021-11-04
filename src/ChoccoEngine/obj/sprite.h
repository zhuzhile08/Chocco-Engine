#pragma once

#include <iostream>
#include <memory>
#include <map>

#include "../Util/math.h"
#include "../Util/loaders.h"
#include "object.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ChoccoEngine {
    class Sprite : public Object {
	protected:
		std::string path;
		SDL_Texture* texture;
		SDL_Rect* clip;
		SDL_Renderer* renderer;
		SDL_Point rotationCenter;
	public:
		Sprite();
		~Sprite();
		void flip();
	};
}
