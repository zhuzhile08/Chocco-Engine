#include <ChoccoEngine/sprite.h>

namespace chocco {
	//consturctors and desturctors
	Sprite::Sprite(std::string name, Vector2 position, Vector2 scale, double rotation) : Object(name, position, scale, rotation), texture(nullptr), path("assets/img/TextureError"), clip(nullptr), rotationCenter({0, 0}) {}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		delete clip;
	}

	void Sprite::destory() {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		delete clip;
	}

	// sprite initializers
	// yes, I didn't put these in a constructor because I don't want to make 100 different overloads of the constructor, just a little different
	// also, this keeps a line pretty short
	void Sprite::initSpriteTexture(Renderer renderer, std::string path) {
		this->path = path;
		texture = loadTexture(renderer.renderer, this->path);
	}

	void Sprite::initSpriteAttributes(SDL_Rect* clip, SDL_Point rotationCenter) {
		this->clip = clip;
		this->rotationCenter = rotationCenter;
	}

	// some functions
	void Sprite::flip() {
		scale = {scale.x * -1, scale.y};
		flipped * -1;
	}

	// getters
	SDL_Texture* Sprite::getTexture() {
		return texture;
	}

	SDL_Rect* Sprite::getClip() {
		return clip;
	}

	SDL_Point Sprite::getRotationCenter() {
		return rotationCenter;
	}

	std::string Sprite::getPath() {
		return path;
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
