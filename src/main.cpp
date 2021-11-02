#include "Engine/window.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

void _initSDL();

int main(int argc, char** args) {
	_initSDL();
	Window window;
	window.update();
	return 0;
}

void _initSDL() {
	// check if everything is initialized
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted & flags) != flags) {
		std::cout << "IMG_Init: Failed to init required png support!" << IMG_GetError() << std::endl;
	}

	if (TTF_Init() != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		IMG_Quit();
		SDL_Quit();
	}
}
