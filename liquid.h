#pragma once

#include "element.h"
#include "grid.h"

class Liquid : public Element {
public:
	int dispersion_factor;

    Liquid(Color color) : Element(color) {}

	void update(Grid& grid, int x, int y) {
        // Below
        if (y + 1 < grid.getHeight() && grid.isEmpty(x, y + 1)) {
            grid.swap(x, y, x, y + 1);
        }
        // Below left
        else if (x - 1 >= 0 && y + 1 < grid.getHeight() && grid.isEmpty(x - 1, y + 1)) {
            grid.swap(x, y, x - 1, y + 1);
        }
        // Below right
        else if (x + 1 < grid.getWidth() && y + 1 < grid.getHeight() && grid.isEmpty(x + 1, y + 1)) {
            grid.swap(x, y, x + 1, y + 1);
        }
        // Left
        else if (x - 1 >= 0 && grid.isEmpty(x - 1, y)) {
            grid.swap(x, y, x-1, y);
        }
        // Right
        else if (x + 1 < grid.getWidth() && grid.isEmpty(x + 1, y)) {
            grid.swap(x, y, x + 1, y);
        }
	}
};