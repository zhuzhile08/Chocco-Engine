#include <ChoccoEngine/MIX_init.h>

namespace ChoccoEngine {
	void initMIX() {
		// Check load
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) != 0) {
			MIXError("SDL Mixer init Error");
		}
	}

	void quitMIX() {
		Mix_Quit();
	}
}
