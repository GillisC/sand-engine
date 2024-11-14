#include "solid.h"

class ImmovableSolid : public Solid {
public:
	
	ImmovableSolid(Color color) : Solid(color) {}

	void update(Grid& grid, int x, int y) override {
		// Do nothing
	}
};