#pragma once

#include "movable_solid.h"

class Sand : MovableSolid {
public:
	Sand();
	void update(Grid& grid, int x, int y) override;

};
