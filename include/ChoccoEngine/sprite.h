#pragma once

#include <iostream>

#include <Cmath.h>
#include <object.h>

#include <SDL.h>

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

/**
 * Sprite Class
 * Pretty basic sprite class, containing basicly everything a sprite could need
 * I kept the constructor so simple, because the constructor would be overly complicated if I'd have to 
 * define all this stuff in a constructor, so you have to make your own constructor in the child class
 **/

namespace chocco {
    class Sprite : public Object {
	protected:
		std::string path = "assets/img/textureError.png";
		SDL_Texture* texture = nullptr;
		SDL_Rect* clip = nullptr;
		SDL_Point rotationCenter = {0, 0};
	public:
		Sprite();
		Sprite(std::string name, Vector2 position, Vector2 scale, double rotation);
		~Sprite();
		void flip();
		double get_width();
		double get_height();
	};
}
