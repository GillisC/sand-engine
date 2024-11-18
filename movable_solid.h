#pragma once

#include "solid.h"
#include "grid.h"

class MovableSolid : public Solid {
public:
	MovableSolid(Color color) : Solid(color) {}

	void update(Grid& grid, int x, int y) override {
        // Below
        if (grid.isInBounds(x, y + 1) && (grid.isLiquid(x, y + 1) || grid.isEmpty(x, y + 1)) ) {
            grid.swap(x, y, x, y + 1);
        }
        // Below left
        else if (grid.isInBounds(x - 1, y + 1) && (grid.isLiquid(x - 1, y + 1) || grid.isEmpty(x - 1, y + 1)) ) {
            grid.swap(x, y, x - 1, y + 1);
        }
        // Below right
        else if (grid.isInBounds(x + 1, y + 1) && (grid.isLiquid(x + 1, y + 1) || grid.isEmpty(x + 1, y + 1)) ) {
            grid.swap(x, y, x + 1, y + 1);
        }
	}
};