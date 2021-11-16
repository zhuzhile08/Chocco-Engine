#pragma once

#include <iostream>
#include <SDL.h>

#include <ChoccoEngine/Cmath.h>
#include <ChoccoEngine/object.h>
#include <ChoccoEngine/loaders.h>

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
		void initSpriteTexture(SDL_Renderer* renderer, std::string path);
		void initSpriteAttributes(SDL_Rect* clip, SDL_Point rotationCenter);

		SDL_Texture* &getTexture = texture;
		SDL_Rect* &getClip = clip;
		SDL_Point &getRotationCenter = rotationCenter;
		std::string &getPath = path;

		double getWidth();
		double getHeight();
	};
}
