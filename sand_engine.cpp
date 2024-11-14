#include "sand_engine.h"


SandEngine::SandEngine(int width, int height, int fps) :
	width(width), height(height), fps(fps), running(true), grid(width, height) {
	
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

	while (running) {
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
				else {
					std::cout << "Key pressed: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				auto selection = grid.getCircleSelection(event.motion.x, event.motion.y, 20);
				for (const auto& tup : selection) {
					int x = std::get<0>(tup);
					int y = std::get<1>(tup);
					grid.set(x, y, std::make_shared<Stone>());
				}
			}
		}

		grid.updateElements();
		grid.displayElements(renderer);

		SDL_RenderPresent(renderer);


	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
