#include <ChoccoEngine/sprite.h>

namespace chocco {
	Sprite::Sprite(std::string name, Vector2 position, Vector2 scale, double rotation) : Object(name, position, scale, rotation), texture(nullptr), path("assets/img/TextureError"), clip(nullptr), rotationCenter({0, 0}) {}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
		delete clip;
	}

	void Sprite::flip() {
		scale = {scale.x * -1, scale.y};
		flipped * -1;
	}

	double Sprite::get_width() {
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

	double Sprite::get_height() {
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
