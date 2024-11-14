#include "sand_engine.h"


SandEngine::SandEngine(int width, int height, int fps) {
	this->width = width;
	this->height = height;
	this->fps = fps;
	this->running = true;
}

void SandEngine::run() {
	init();

	SDL_Event event;

	while (running) {
		SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}


		SDL_RenderPresent(renderer);


	}

	SDL_Quit();
}


void SandEngine::init() {

	// Initialize SDL
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