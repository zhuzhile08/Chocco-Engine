#include <ChoccoEngine/TTF_init.h>

namespace ChoccoEngine {
	void initTTF() {
		if (TTF_Init() != 0) {
			TTFError("TTF init error");
		}
	}

	void quitTTF() {
		TTF_Quit();
	}
}
