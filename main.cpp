#define SDL_MAIN_HANDLED

#include <iostream>
#include "sand_engine.h"

int width = 720;
int height = 480;
int fps = 60;

int main(int argc, char* argv[]) {
	SandEngine sandEngine = SandEngine(width, height, fps);

	sandEngine.run();

	return 0;
}