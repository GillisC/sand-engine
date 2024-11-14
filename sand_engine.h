#pragma once

#include <SDL2/SDL.h>

#include <iostream>

#include "grid.h"
#include "sand.h"
#include "water.h"
#include "stone.h"

class SandEngine {
public:
	int width, height, fps;
	bool running;
	Grid grid;
	
	enum Material {
		STONE,
		WATER,
		SAND
	};

	SandEngine(int width, int height, int fps);
	void run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	void placeMaterial(Grid& grid, int x, int y, Material material);

	
};