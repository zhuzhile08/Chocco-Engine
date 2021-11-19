#pragma once

#ifndef ndebug
#include <ChoccoEngine/error.h>
#endif

#include <SDL_image.h>
#include <assert.h>

namespace chocco {
	void initIMGType(int flag);

	// initialize all sorts of images
	void initPNG();
	void initJPG();
	void initTIFF();
	void initWEBP();

	void initIMGAll();

	void quitIMG();
}
