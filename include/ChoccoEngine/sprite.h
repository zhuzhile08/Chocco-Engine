#pragma once

#include <iostream>

#include <Cmath.h>
#include <object.h>

#include <SDL.h>

namespace chocco {
    class Sprite : public Object {
	protected:
		std::string path;
		SDL_Texture* texture;
		SDL_Rect* clip;
		SDL_Point rotationCenter;
	public:
		Sprite();
		~Sprite();
		void flip();
		void getWidth();
		void getHeight();
	};
}
