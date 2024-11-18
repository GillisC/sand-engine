#include "water.h"

Water::Water() : Liquid(varyColor(Color(0, 0, 255, 200))) {
	dispersion_factor = 5;
}

bool Water::isFlammable() const { return true; }