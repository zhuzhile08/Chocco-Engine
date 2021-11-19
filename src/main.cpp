#define SDL_MAIN_HANDLED

#include <ChoccoEngine/initAll.h>
#include <ChoccoEngine/gameManager.h>

int main(int argc, char** args) {
	chocco::initAll();
	chocco::GameManager window;
	window.update();
	return 0;
}
