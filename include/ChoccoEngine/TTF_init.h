#pragma once

#include <SDL_ttf.h>

#ifndef ndebug
#include "error.h"
#endif

namespace chocco {
	void initTTF();
	void quitTTF();
}
