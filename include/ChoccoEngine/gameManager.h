/**
* Window class
* creates window, renderers, loads textures and updates everything
* updates everything
**/

#pragma once

#include <ChoccoEngine/gameVar.h>
#include <ChoccoEngine/renderer.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace chocco {
	class GameManager
	{
	protected:
		// events
		SDL_Event event;

		SDL_Window* window;
		Renderer renderer;

		void events();

		SDL_Texture *layers[20];

	public:
		bool running;

		GameManager();

		void destroy();
		void loadScene();
		void unloadScene();
		void update();
	};
}
