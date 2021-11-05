#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

namespace ChoccoEngine {
	void SDLError(std::string message);
	void IMGError(std::string message);
	void TTFError(std::string message);
	void MIXError(std::string message);
}
