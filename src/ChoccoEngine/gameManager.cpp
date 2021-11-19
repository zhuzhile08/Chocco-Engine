/**
 * Main Window
 * You should NOT directly inherit this window class in the main.cpp file, because it is missing the "neccecary" spritegroups.
 * instead, you should make a new class in the main source folder, which contains a child of this window class and add all your
 other stuff in there.
**/

#include <ChoccoEngine/gameManager.h>

namespace chocco {
	GameManager::GameManager() {
		// set running to true
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
#ifndef ndebug
		if (window == nullptr) {
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();

			SDLError("SDL create window Error");

			delete[] this;
		}
#endif

		renderer = Renderer(window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		running = true;

		test = Sprite("bob", {100, 100}, {1, 1}, 0);
		test.initSpriteTexture(renderer.renderer, "assets/img/TextureError.png");
	}

	GameManager::~GameManager() {
		SDL_DestroyWindow(window);
		renderer.destroy();
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
	}

	void GameManager::events() {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
	}

	void GameManager::update() {
		while (running) {
			events();
		
			renderer.clear();

			std::cout << test.getWidth() << std::endl;

			renderer.drawSprite(test);

			renderer.present();
		}
	}
}
