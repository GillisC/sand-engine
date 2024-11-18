#pragma once

#include "solid.h"

class Grid;

class ImmovableSolid : public Solid {
public:
	
	ImmovableSolid(Color color) : Solid(color) {}

	void update(Grid& grid, int x, int y) override {
		// Do not update position
	}
};