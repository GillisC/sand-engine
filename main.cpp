#define SDL_MAIN_HANDLED

#include <iostream>

#include <SDL2/SDL.h>

int width = 720;
int height = 480;
int fps = 60;
bool running = true;


int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: " << SDL_GetError() << std::endl;
	}
	else {
		std::cout << "SDL succesfully initialized!" << std::endl;
	}

	SDL_Quit();
	return 0;
}