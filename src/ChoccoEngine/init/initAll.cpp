#include <ChoccoEngine/initAll.h>

namespace chocco{
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
