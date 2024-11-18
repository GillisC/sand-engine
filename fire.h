#pragma once

#include "element.h"

class Fire : public Element {
public:
	Fire();
	void update(Grid& grid, int x, int y);
	Color getColor() const override;
	
	bool isAir() const override { return false; }
	bool isFlammable() const override { return false; }

private:
	double extinguish_chance = 0.1;
};