/**
 * Main Window
 * You should NOT directly inherit this window class in the main.cpp file, because it is missing the "neccecary" spritegroups.
 * instead, you should make a new class in the main source folder, which contains a child of this window class and add all your
 other stuff in there.
**/

#include "gameManager.h"

namespace ChoccoEngine {
GameManager::GameManager() {
		// set running to true
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
#ifndef ndebug
		if (window == nullptr) {
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();

			std::cout << "SDL create window Error" << SDL_GetError << std::endl;

			delete[] this;
		}
#endif

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
#ifndef ndebug
		if (renderer == nullptr) {
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();

			std::cout << "SDL create renderer Error" << SDL_GetError << std::endl;
		}
#endif

		running = true;

		helloLmao = std::make_shared<Font> (renderer, "assets/ttf/sample.ttf", "HelloLmao", Color(255, 0, 255, 255), Vector2(69, 420), "Haha lmao hello world lol.", 16);

		test = std::make_shared<Sprite> (renderer, "assets/img/TextureError.png", Vector2(0, 0), Vector2(1, 1), 0, "test");
	}

	GameManager::~GameManager() {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
	}


	void GameManager::drawSprite(std::shared_ptr<Sprite> sprite) {
		SDL_Rect dst;
		
		int w, h;

		SDL_QueryTexture(sprite->texture, NULL, NULL, &w, &h);

		std::cout << SDL_GetError << " / ";

		dst.w = w * int (sprite->scale.x);
		dst.h = h * int (sprite->scale.y);
		dst.x = int (sprite->position.x) - int (sprite->rotationCenter.x / 2);
		dst.y = int (sprite->position.y) - int (sprite->rotationCenter.y / 2);


		std::cout << dst.w << " / " << dst.h << " / " << dst.x / 2 << " / " << dst.y / 2 << std::endl;

		if (sprite->rotation != 0) {
			SDL_Point rotationCenter = sprite->rotationCenter;
			SDL_RenderCopyEx(renderer, sprite->texture, NULL, &dst, sprite->rotation, &rotationCenter, SDL_FLIP_NONE);
		} else {
			SDL_RenderCopy(renderer, sprite->texture, NULL, &dst);
		}
		
	}

	void GameManager::drawFont(std::shared_ptr<Font> font) {
		SDL_Rect dst;

		int w, h;

		SDL_QueryTexture(font->texture, NULL, NULL, &w, &h);

		dst.w = w * int (font->scale.x);
		dst.h = h * int (font->scale.y);
		dst.x = int (font->position.x);
		dst.y = int (font->position.y);

		SDL_RenderCopy(renderer, font->texture, NULL, &dst); 
	}

	void GameManager::drawAllSprites(std::shared_ptr<SpriteGroup> group) {
		std::map<std::string, std::shared_ptr<Sprite>>::iterator element;

		for (element = group->group.begin(); element != group->group.end(); ++element) {
			drawSprite((*element).second);
		}
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
		
			SDL_RenderClear(renderer);

			drawSprite(test);
			drawFont(helloLmao);

			SDL_RenderPresent(renderer);
		}
	}
}
