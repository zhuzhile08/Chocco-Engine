#include "color.h"

namespace ChoccoEngine {
	/**
	 * Since I have no idea how SDL_Color works, I just created this small thing that creates a color for me
	 * Has 4 values for the colors (a is for alpha)
	**/

	SDL_Color Color(int r, int g, int b, int a) {
		SDL_Color color;
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
		return color;
	}
}
