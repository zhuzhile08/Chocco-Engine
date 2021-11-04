#include "sprite.h"

namespace ChoccoEngine {
	Sprite::Sprite() : texture(nullptr), renderer(nullptr), path("assets/img/TextureError"), clip(nullptr), rotationCenter({0, 0}){}

	Sprite::~Sprite() {
		delete texture;
		delete clip;
	}
}
