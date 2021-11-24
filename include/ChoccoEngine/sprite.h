#pragma once

#include <string>
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
		std::string path = "data/img/textureError.png";
		SDL_Texture* texture = nullptr;
		SDL_Rect* clip = NULL;
		SDL_FPoint rotationCenter = {0, 0};
	public:
		Sprite();
		Sprite(std::string name, Vector2 position, Vector2 scale, double rotation);

		virtual void destory();
		
		void flip();
		void initSpriteTexture(SDL_Renderer* renderer, std::string path);
		void initSpriteAttributes(SDL_Rect* clip, SDL_FPoint rotationCenter);

		SDL_Texture* getTexture();
		SDL_Rect* getClip();
		SDL_FPoint getRotationCenter();
		std::string getPath();
		
		double getWidth();
		double getHeight();
	};
}
