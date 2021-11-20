/**
* Window class
* creates window, renderers, loads textures and updates everything
* updates everything
**/

#pragma once

#include <memory>

#include <ChoccoEngine/gameVar.h>
#include <ChoccoEngine/sprite.h>
#include <ChoccoEngine/font.h>
#include <ChoccoEngine/renderer.h>
#include <ChoccoEngine/error.h>
#include <ChoccoEngine/SDLExt.h>
#include <iostream>

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
		
		// void drawAllSprites(std::shared_ptr<SpriteGroup> group);

		Sprite test;
		Font text;

	public:
		bool running;
		GameManager();
		~GameManager();
		void loadScene();
		void unloadScene();
		void update();
		
	};
}

