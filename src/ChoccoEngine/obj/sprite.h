#pragma once

#include <iostream>
#include <memory>
#include <map>

#include "../Util/math.h"
#include "../Util/loaders.h"
#include "gameObj.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ChoccoEngine {
    struct Sprite : public GameObj {
		std::string path;
		SDL_Texture* texture;
		SDL_Rect* clip;
		SDL_Point rotationCenter;
		Sprite();
		Sprite(SDL_Renderer* renderer, std::string path, std::string name, Vector2 position, Vector2 scale, float rotation);
		Sprite(SDL_Renderer* renderer, std::string path, std::string name, Vector2 position, Vector2 scale, float rotation, int clipSize[4]);
		Sprite(SDL_Renderer* renderer, std::string path, std::string name, Vector2 position, Vector2 scale, float rotation, int clipSize[4], int rCx, int rCy);
		~Sprite();
	};
}
