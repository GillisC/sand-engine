#include "solid.h"

class UnmovableSolid : public Solid {
public:
	
	UnmovableSolid(Color color) : Solid(color) {}
	void update(Grid& grid, int x, int y) override {
		// Do nothing
	}
};