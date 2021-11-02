/**
* Window class
* creates window, renderers, loads textures and updates everything
* updates everything
**/

#pragma once

#include <iostream>
#include <memory>

#include "gameVar.h"
#include "gameObj.h"
#include "SDL_addons.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Window
{
protected:
	// events
	SDL_Event event;

	SDL_Window* window;
	SDL_Renderer* renderer;

	void events();

	void drawSprite(std::shared_ptr<Sprite> sprite);
	void drawTexture(SDL_Texture* texture, int x, int y);
	void drawFont(std::shared_ptr<Font> font);
	
	void drawAllSprites(std::shared_ptr<SpriteGroup> group);

	std::shared_ptr<Font> helloLmao;

	std::shared_ptr<Sprite> test;

	SDL_Texture* texture;

public:
	bool running;
	Window();
	~Window();
	void loadScene();
	void unloadScene();
	void update();
	
};

