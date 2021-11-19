#pragma once

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

#include <SDL_mixer.h>
#include <assert.h>

namespace chocco {
	void initMIX();
	void quitMIX();
}
