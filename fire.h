#pragma once

#include "element.h"

class Grid;

class Fire : public Element {
public:
	Fire();
	void update(Grid& grid, int x, int y);
	Color getColor() const override;
	

private:
	double extinguish_chance = 0.1;
};