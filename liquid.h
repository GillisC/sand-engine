#pragma once

#include <random>

#include "element.h"
#include "grid.h"


class Liquid : public Element {
public:
	int dispersion_factor = 1;

    Liquid(Color color) : Element(color) {}

	void update(Grid& grid, int x, int y) {
        // Below
        if (y + 1 < grid.getGridHeight() && grid.isEmpty(x, y + 1)) {
            grid.swap(x, y, x, y + 1);
        }
        // Below left
        else if (x - 1 >= 0 && y + 1 < grid.getGridHeight() && grid.isEmpty(x - 1, y + 1)) {
            grid.swap(x, y, x - 1, y + 1);
        }
        // Below right
        else if (x + 1 < grid.getGridWidth() && y + 1 < grid.getGridHeight() && grid.isEmpty(x + 1, y + 1)) {
            grid.swap(x, y, x + 1, y + 1);
        }
        // If there is space to the left or right, choose direction randomly
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1); // distribution in range [1, 6]

        if (dist(rng) == 0) {
            // Left
            if (x - 1 >= 0 && grid.isEmpty(x - 1, y)) {
                grid.swap(x, y, disperse(grid, x, y, -1), y);
            }
            // Right
            else if (x + 1 < grid.getGridWidth() && grid.isEmpty(x + 1, y)) {
                grid.swap(x, y, disperse(grid, x, y, 1), y);
            }
        }
        else if (dist(rng) == 1) {
            // Right
            if (x + 1 < grid.getGridWidth() && grid.isEmpty(x + 1, y)) {
                grid.swap(x, y, disperse(grid, x, y, 1), y);
            }
            // Left
            else if (x - 1 >= 0 && grid.isEmpty(x - 1, y)) {
                grid.swap(x, y, disperse(grid, x, y, -1), y);
            }
        }
	}
private:
    int disperse(Grid& grid, int x, int y, int direction) {
        // Travels in the x direction and based on the dispersion factor finds the next cell to occupy
        int new_x = 0;
        for (int i = 0; i < dispersion_factor; i++) {
            int dx = direction * i;
            if (x + dx >= 0 && x + dx < grid.getGridWidth() && grid.isEmpty(x+dx, y)) {
                new_x = dx + x;
            }
        }
        return new_x;
    }
};