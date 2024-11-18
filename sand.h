#pragma once

#include "movable_solid.h"

class Sand : public MovableSolid {
public:
	Sand();
	bool isAir() const override { return false; }
};
