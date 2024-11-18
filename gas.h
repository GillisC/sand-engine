#pragma once

#include "element.h"
#include "grid.h"

class Grid;

// Behavoir of gases is to rise instead of fall down, otherwise they behave much like liquids.
// Gases should disperse quicker if its clumped together and should "decay" into something when cooled down.
class Gas : public Element {

public:
    int dispersion_factor = 1;

    Gas(Color color) : Element(color) {}

	void update(Grid& grid, int x, int y) override {
        // Up
        if (grid.isInBounds(x, y - 1) && grid.isEmpty(x, y - 1)) {
            grid.swap(x, y, x, y - 1);
        }
        // Up to the left
        else if (grid.isInBounds(x - 1, y - 1) && grid.isEmpty(x - 1, y - 1)) {
            grid.swap(x, y, x - 1, y - 1);
        }
        // Up to the right
        else if (grid.isInBounds(x + 1, y - 1) && grid.isEmpty(x + 1, y - 1)) {
            grid.swap(x, y, x + 1, y - 1);
        }
        // If there is space to the left or right, choose direction randomly
        
        else if ((grid.isInBounds(x - 1, y) && grid.isEmpty(x - 1, y)) || (grid.isInBounds(x + 1, y) && grid.isEmpty(x + 1, y))) {
            if (randomReal() <= 0.5) {
                // Left
                if (grid.isInBounds(x - 1, y) && grid.isEmpty(x - 1, y)) {
                    grid.swap(x, y, disperse(grid, x, y, -1), y);
                }
                // Right
                else if (grid.isInBounds(x + 1, y) && grid.isEmpty(x + 1, y)) {
                    grid.swap(x, y, disperse(grid, x, y, 1), y);
                }
            }
            else {
                // Right
                if (grid.isInBounds(x + 1, y) && grid.isEmpty(x + 1, y)) {
                    grid.swap(x, y, disperse(grid, x, y, 1), y);
                }
                // Left
                else if (grid.isInBounds(x - 1, y) && grid.isEmpty(x - 1, y)) {
                    grid.swap(x, y, disperse(grid, x, y, -1), y);
                }
            }
        }
        
    }

    bool isGas() const override { return true; }

private:

    int disperse(Grid& grid, int x, int y, int direction) {
        // Travels in the x direction and based on the dispersion factor finds the next cell to occupy
        int new_x = x;
        for (int i = 1; i <= dispersion_factor; i++) {
            int temp = direction * i + x;
            if (grid.isInBounds(temp, y) && grid.isEmpty(temp, y)) {
                new_x = temp;
            }
            else {
                return new_x;
            }
        }
        return new_x;
    }
};