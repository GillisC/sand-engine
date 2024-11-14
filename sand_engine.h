#pragma once

#include <iostream>

#include <SDL2/SDL.h>

class SandEngine {
public:
	int width, height, fps;
	bool running;

	SandEngine(int width, int height, int fps);
	void run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	void init();
};