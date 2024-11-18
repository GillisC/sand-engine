#pragma once

#include "element.h"

class Fire : public Element {
	Fire();
	void update(Grid& grid, int x, int y);
	void spread(Grid& grid, int x, int y);
	Color getColor() const override;
};