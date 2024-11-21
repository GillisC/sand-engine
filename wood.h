#pragma once

#include "immovable_solid.h"

class Wood : public ImmovableSolid {
public:
	Wood();
	void update(Grid& grid, int x, int y) override;
	bool isAir() const override { return false; }
	bool isFlammable() const override { return true; }
};	