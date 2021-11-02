#pragma once

#include <iostream>
#include <memory>
#include <map>

#include "../Util/math.h"
#include "../Util/loaders.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ChoccoEngine {
	struct GameObj {
		Vector2 position, scale;
		float rotation;
		std::string name;
		GameObj();
		GameObj(Vector2 position, Vector2 scale, float rotation, std::string name);
	};
}
