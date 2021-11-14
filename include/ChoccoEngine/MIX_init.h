#pragma once

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

#include <SDL_mixer.h>

namespace chocco {
	void initMIX();
	void quitMIX();
}
