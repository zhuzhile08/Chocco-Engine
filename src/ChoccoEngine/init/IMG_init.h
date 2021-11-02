#pragma once

#include <SDL_image.h>
#include "../Util/SDL_Error.h"

namespace ChoccoEngine {
	void initIMG();

	void initIMGTypes(int flag);

	// initialize all sorts of images
	void initPNG();
	void initJPG();
	void initTIFF();
	void initWEBP();

	void initIMGAll();

	void quitIMG();
}
