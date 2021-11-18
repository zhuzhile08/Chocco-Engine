#include <ChoccoEngine/error.h>

namespace chocco {
	void SDLError(std::string message) {
		std::cout << message << ": " << SDL_GetError() << std::endl;
	}

	void IMGError(std::string message) {
		std::cout << message << ": " << IMG_GetError() << std::endl;
	}

	void TTFError(std::string message) {
		std::cout << message << ": " << TTF_GetError() << std::endl;
	}

	void MIXError(std::string message) {
		std::cout << message << ": " << Mix_GetError() << std::endl;
	}
}
