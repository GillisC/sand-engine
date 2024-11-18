#include "fire.h"
#include "grid.h"

Fire::Fire() : Element(Color(226, 88, 34, 255)) {}

void Fire::update(Grid& grid, int x, int y) {
	std::vector<std::pair<int, int>> neighbours = { {x, y + 1}, {x + 1, y}, {x, y - 1}, {x - 1, y} };

	for (auto [nx, ny] : neighbours) {
		if (grid.isInBounds(nx, ny) && grid.get(nx, ny)->isFlammable()) {
			grid.set(nx, ny, std::make_shared<Fire>());
		}
	}

	double val = randomReal();
	if (val <= extinguish_chance) {
		grid.remove(x, y);
	}

}

Color Fire::getColor() const {
	switch (randomInt(1, 3)) {
	case 1:
		return Color(226, 88, 34, 255);
	case 2:
		return Color(226, 184, 34, 255);
	case 3: 
		return Color(244, 228, 170, 255);
	default:
		return Color(255, 255, 255, 255);
	}
}	