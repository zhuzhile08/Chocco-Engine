#include "SDL_init.h"

// initialize SDL, what else to say

namespace ChoccoEngine {
	void initSDL() {
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			SDLError("SDL Init Error");
		}

		if (SDL_Init(SDL_INIT_AUDIO) == -1) {
			printf("SDL_Init: %s\n", SDL_GetError());
			exit(1);
		}
	}

	void quitSDL() {
		SDL_Quit();
	}
}
