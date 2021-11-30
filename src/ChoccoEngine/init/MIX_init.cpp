#include <ChoccoEngine/MIX_init.h>

namespace chocco {
// initialize SDL_Mixer
	void initMIX() {
#ifndef ndebug
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) != 0) {
			MIXError("SDL Mixer init Error");
		}
#endif
#ifndef debug
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
#endif
	}

// Quit SDL_Mixer
	void quitMIX() {	
		Mix_CloseAudio();
	}
}
