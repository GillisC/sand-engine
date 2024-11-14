#pragma once

#include <SDL2/SDL.h>

#include <iostream>

#include "grid.h"
#include "sand.h"

class SandEngine {
public:
	int width, height, fps;
	bool running;
	Grid grid;

	SandEngine(int width, int height, int fps);
	void run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	void init();
};