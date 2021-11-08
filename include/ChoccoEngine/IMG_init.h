#pragma once

#include <SDL_image.h>
#include <error.h>

namespace ChoccoEngine {
	void initIMG();

	void initIMGType(int flag);

	// initialize all sorts of images
	void initPNG();
	void initJPG();
	void initTIFF();
	void initWEBP();

	void initIMGAll();

	void quitIMG();
}
