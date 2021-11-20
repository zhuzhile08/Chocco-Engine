#include <SDL.h>

/**
 * Extensions for the SDL library
 * it's here to make my (your) life easier
 * I'll probably extend this even further down the line
**/

namespace chocco {
	SDL_Color Color(int r, int g, int b, int a);

	SDL_FPoint Point(double x, double y);
}