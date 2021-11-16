#include <ChoccoEngine/sprite.h>

namespace chocco {
	Sprite::Sprite(std::string name, Vector2 position, Vector2 scale, double rotation) : Object(name, position, scale, rotation), texture(nullptr), path("assets/img/TextureError"), clip(nullptr), rotationCenter({0, 0}) {}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		delete clip;
	}

	void Sprite::flip() {
		scale = {scale.x * -1, scale.y};
		flipped * -1;
	}

	void Sprite::initSpriteTexture(SDL_Renderer* renderer, std::string path) {
		this->path = path;
		texture = loadTexture(renderer, this->path);
	}

	void Sprite::initSpriteAttributes(SDL_Rect* clip, SDL_Point rotationCenter) {
		this->clip = clip;
		this->rotationCenter = rotationCenter;
	}

	double Sprite::getWidth() {
		int w;
#ifndef ndebug
		if (texture != nullptr) SDL_QueryTexture(texture, NULL, NULL, &w, NULL);
		else {
			IMGError("Sprite is a null pointer error");
			return 0;
		}
#endif
#ifndef debug
		SDL_QueryTexture(texture, NULL, NULL, &w, NULL);
#endif
		return double(w);
	}

	double Sprite::getHeight() {
		int h;
#ifndef ndebug
		if (texture != nullptr) SDL_QueryTexture(texture, NULL, NULL, NULL, &h);
		else {
			IMGError("Sprite is a null pointer error");
			return 0;
		}
#endif
#ifndef debug
		SDL_QueryTexture(texture, NULL, NULL, NULL, &h);
#endif
		return double(h);
	}
}
