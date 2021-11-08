#include <ChoccoEngine/initAll.h>

namespace ChoccoEngine {
	void initAll() {
        initSDL();
        initIMGAll();
        initTTF();
        initMIX();
    }

	void quitAll() {
        quitSDL();
        quitIMG();
        quitTTF();
        quitMIX();
    }
}
