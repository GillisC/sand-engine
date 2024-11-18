#pragma once

#include "element.h"

class Air : public Element {
public:
	Air();
	void update(Grid& grid, int x, int y) override;
	bool isAir() const override { return true; }
	bool isFlammable() const override { return false; }
};