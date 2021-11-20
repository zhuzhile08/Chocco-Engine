#include <ChoccoEngine/SDLExt.h>

namespace chocco {
	/**
	 * An extension for SDL_Color
	**/

	SDL_Color Color(int r, int g, int b, int a) {
		SDL_Color color;
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
		return color;
	}

	/**
	 * An extension for the SDL_Point (FPoint)
	**/

	SDL_FPoint Point(double x, double y) {
		SDL_FPoint point = {float(x), float(y)};
		return point;
	}
}
