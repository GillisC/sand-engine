#pragma once

#include <SDL2/SDL.h>

#include <iostream>

#include "grid.h"
#include "sand.h"
#include "water.h"
#include "stone.h"
#include "steam.h"
#include "fire.h"
#include "wood.h"

class Grid;

class SandEngine {
public:
	int width, height, fps, pixelSize;
	bool running;
	Grid grid;
	
	enum Material {
		STONE,
		WATER,
		SAND,
		STEAM,
		WOOD,
		FIRE,
		OIL
	};

	SandEngine(int width, int height, int fps, int pixelSize);
	void run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	void placeMaterial(Grid& grid, int x, int y, Material material);

	
};