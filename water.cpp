#include "water.h"

Water::Water() : Liquid(varyColor(Color(0, 0, 255, 100))) {
	dispersion_factor = 5;
}
