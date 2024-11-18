#pragma once

#include "liquid.h"

class Water : public Liquid {
public:
	Water();

	bool isFlammable() const override;
};