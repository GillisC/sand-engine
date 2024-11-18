#pragma once

#include "immovable_solid.h"

class Stone : public ImmovableSolid {
public:
	Stone();
	bool isAir() const override { return false; }
};