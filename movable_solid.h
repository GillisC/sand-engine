
#include "solid.h"
#include "grid.h"

class MovableSolid : public Solid {
public:
	MovableSolid(Color color) : Solid(color) {}

	void update(Grid& grid, int x, int y) {
        // Below
        if (y + 1 < grid.getHeight() && grid.isEmpty(x, y + 1)) {
            grid.swap(x, y, x, y + 1);
        }
        // Below left
        else if (x - 1 >= 0 && y + 1 < grid.getHeight() && grid.isEmpty(x - 1, y + 1)) {
            grid.swap(x, y, x - 1, y + 1);
        }
        // Below right
        else if (x + 1 >= 0 && y + 1 < grid.getHeight() && grid.isEmpty(x + 1, y + 1)) {
            grid.swap(x, y, x + 1, y + 1);
        }
	}
};