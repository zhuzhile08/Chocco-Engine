#pragma once

#include <SDL.h>

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

namespace chocco {
	void initSDL();
	void quitSDL();
}
