#pragma once

#ifndef ndebug
#include "error.h"
#endif

#include <SDL_mixer.h>

namespace chocco {
	void initMIX();
	void quitMIX();
}
