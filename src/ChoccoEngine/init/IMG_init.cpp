#include <ChoccoEngine/IMG_init.h>

// initialize SDL_image

namespace chocco {
	void initIMGType(int flag) {
#ifndef ndebug
		int initted = IMG_Init(flag);

		if ((initted & flag) != flag) {
			IMGError("IMG init failed to load required fomat support(s)");
		}
#endif
	}

	void initPNG() {
		initIMGType(IMG_INIT_PNG);
	}

	void initJPG() {
		initIMGType(IMG_INIT_JPG);
	}
	
	void initTIF() {
		initIMGType(IMG_INIT_TIF);
	}

	void initWEBP() {
		initIMGType(IMG_INIT_WEBP);
	}

// function to initialize everything

	void initIMGAll() {
		if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
			IMGError("IMG init error");
		}

		initPNG();
		initJPG();
		initTIF();
		initWEBP();
	}

	void quitIMG() {
		IMG_Quit();
	}

}
