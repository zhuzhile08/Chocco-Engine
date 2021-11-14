#include <ChoccoEngine/SDL_init.h>

// initialize SDL, what else to say

namespace chocco {
	void initSDL() {
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			SDLError("SDL Init Error");
		}

		if (SDL_Init(SDL_INIT_AUDIO) == -1) {
			SDLError("SDL audio init error");
		}
	}

	void quitSDL() {
		SDL_Quit();
	}
}
