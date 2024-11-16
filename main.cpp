#define SDL_MAIN_HANDLED

#include "sand_engine.h"

const int width = 720;
const int height = 480;
const int fps = 60;
const int pixelSize = 4;

int main(int argc, char* argv[]) {
	SandEngine sandEngine = SandEngine(width, height, fps, pixelSize);

	sandEngine.run();

	return 0;
}