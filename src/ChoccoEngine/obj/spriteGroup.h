#pragma once

#include <iostream>
#include <memory>
#include <map>

#include "../Util/math.h"
#include "../Util/loaders.h"
#include "sprite.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ChoccoEngine {
    class SpriteGroup {
	public:
		std::map <std::string, std::shared_ptr<Sprite>> group;
		SpriteGroup();
		void add(std::shared_ptr<Sprite> obj);
		void remove(std::string name, int check);
	};
}
