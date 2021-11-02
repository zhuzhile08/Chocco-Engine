#include "sprite.h"

namespace ChoccoEngine {
	Sprite::Sprite(SDL_Renderer* renderer, std::string path, std::string name, Vector2 position, Vector2 scale, float rotation)
		: GameObj(position, scale, rotation, name), path(path), texture(loadTexture(renderer, this->path)){
		int w, h;
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		rotationCenter = {w/2, h/2};
	}

	Sprite::Sprite(SDL_Renderer* renderer, std::string path, std::string name, Vector2 position, Vector2 scale, float rotation, int clipSize[4])
		: path(path), GameObj(position, scale, rotation, name)  {
		texture = loadTexture(renderer, this->path);

		clip->x = clipSize[0];
		clip->y = clipSize[1];
		clip->w = clipSize[2];
		clip->h = clipSize[3];

		int w, h;
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		rotationCenter = {w/2, h/2};
	}

	Sprite::Sprite(SDL_Renderer* renderer, std::string path, std::string name, Vector2 position, Vector2 scale, float rotation, int clipSize[4], int rCx, int rCy)
		: path(path), GameObj(position, scale, rotation, name)  {
		texture = loadTexture(renderer, this->path);

		clip->x = clipSize[0];
		clip->y = clipSize[1];
		clip->w = clipSize[2];
		clip->h = clipSize[3];

		rotationCenter = {rCx , rCy};
	}

	Sprite::~Sprite() {
		delete texture;
		delete clip;
	}
}
