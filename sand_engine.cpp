#include "sand_engine.h"



SandEngine::SandEngine(int width, int height, int fps, int pixelSize = 1) :
	width(width), height(height), fps(fps), running(true), grid(width, height, pixelSize), pixelSize(pixelSize) {
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: " << SDL_GetError() << std::endl;
	}
	else {
		std::cout << "SDL succesfully initialized!" << std::endl;
	}

	// Create window
	this->window = SDL_CreateWindow(
		"Sand Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_RESIZABLE
	);
	if (window == NULL) {
		std::cout << "Error initilizing window: " << SDL_GetError() << std::endl;
	}
	else {
		std::cout << "Window successfully created" << std::endl;
	}

	// Create renderer
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		std::cout << "Error initilizing renderer: " << SDL_GetError() << std::endl;
	}
	else {
		std::cout << "Renderer successfully created" << std::endl;
	}
}


void SandEngine::run() {
	SDL_Event event;
	Material currentMaterial = WATER;

	int frameDelay = 1000 / fps;

	while (running) {
		Uint32 frameStart = SDL_GetTicks();
		
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				if (event.key.keysym.sym == SDLK_1) {
					currentMaterial = SandEngine::Material::STONE;
				}
				if (event.key.keysym.sym == SDLK_2) {
					currentMaterial = SandEngine::Material::WATER;
				}
				if (event.key.keysym.sym == SDLK_3) {
					currentMaterial = SandEngine::Material::SAND;
				}
				if (event.key.keysym.sym == SDLK_4) {
					currentMaterial = SandEngine::Material::STEAM;
				}
				if (event.key.keysym.sym == SDLK_5) {
					currentMaterial = SandEngine::Material::FIRE;
				}
				if (event.key.keysym.sym == SDLK_6) {
					currentMaterial = SandEngine::Material::WOOD;
				}
				else {
					//std::cout << "Key pressed: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
				}
			}
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON_LMASK) {

				// Returns a tuple of coordinates
				auto selection = grid.getCircleSelection(event.motion.x, event.motion.y, 5, 0.8);
				for (const auto& tup : selection) {
					int x = std::get<0>(tup);
					int y = std::get<1>(tup);
					placeMaterial(grid, x, y, currentMaterial);
				}
			}
		}

		grid.updateElements();
		grid.displayElements(renderer);

		SDL_RenderPresent(renderer);

		// Limits the framerate
		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void SandEngine::placeMaterial(Grid& grid, int x, int y, SandEngine::Material material) {
	// Places the currently selected material
	switch (material) 
	{
		case SandEngine::Material::STONE:
			grid.set(x, y, std::make_shared<Stone>());
			break;
		case SandEngine::Material::WATER:
			grid.set(x, y, std::make_shared<Water>());
			break;
		case SandEngine::Material::SAND:
			grid.set(x, y, std::make_shared<Sand>());
			break;
		case SandEngine::Material::STEAM:
			grid.set(x, y, std::make_shared<Steam>());
			break;
		case SandEngine::Material::FIRE:
			grid.set(x, y, std::make_shared<Fire>());
			break;
		case SandEngine::Material::WOOD:
			grid.set(x, y, std::make_shared<Wood>());
			break;
	}
}
