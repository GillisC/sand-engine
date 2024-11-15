#include "grid.h"

Grid::Grid(int w, int h)
    : width(w), height(h) {
    std::cout << "Constructor called with width: " << width << ", height: " << height << std::endl;

    // Initialize the grid
    grid = std::vector<std::vector<std::shared_ptr<Element>>>(height, std::vector<std::shared_ptr<Element>>(width, nullptr));

    std::cout << "Grid initialized with dimensions: " << width << " x " << height << std::endl;
    std::cout << "grid.size(): " << grid.size() << std::endl;
    if (!grid.empty()) {
        std::cout << "grid[0].size(): " << grid[0].size() << std::endl;
    }
}


// Clears the grid
void Grid::clear() {
    grid.assign(height, std::vector<std::shared_ptr<Element>>(width, nullptr));
}

void Grid::set(int x, int y, std::shared_ptr<Element> element) {
    if (isInBounds(x, y)) {
        grid[y][x] = element;
    }
    else {
        std::cerr << "Out of bounds, trying to insert element into: (" << x << ", " << y << ")" << std::endl;
    }
}

void Grid::swap(int x1, int y1, int x2, int y2) {
    if (isInBounds(x1, y1) && isInBounds(x2, y2)) {
        auto temp = grid[y1][x1];
        grid[y1][x1] = grid[y2][x2];
        grid[y2][x2] = temp;
    }
    else {
        std::cerr << "Out of bounds, trying to swap element: (" << x1 << ", " << y1 << ")" << "with (" << x2 << ", " << y2 << ")" << std::endl;
    }
}

bool Grid::isEmpty(int x, int y) const {
    if (isInBounds(x, y)) {
        if (grid[y][x] == nullptr) {
            return true;
        }
        else return false;
    }
    else {
        std::cerr << "Out of bounds, trying to check if cell is empty at: (" << x << ", " << y << ")" << std::endl;
    }
    return false;
}


void Grid::updateElements() {
    // Go backwards through the grid to not update the same cell more than once
    for (int i = height - 1; i >= 0; i--) {
        for (int j = width - 1; j >= 0; j--) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->update(*this, j, i);
            }
        }
    }
}

void Grid::displayElements(SDL_Renderer* renderer) const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->display(renderer, j, i);
            }
        }
    }
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

std::string Grid::toString() const {
    return "Grid(width=" + std::to_string(width) + ", height=" + std::to_string(height) + ")";
}

bool Grid::isInBounds(int x, int y) const {
    return x >= 0 && x <= width && y >= 0 && y <= height;
}

double distanceSquared(int x1, int y1, int x2, int y2) {
    return static_cast<double>((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

std::vector<std::tuple<int, int>> Grid::getCircleSelection(int x, int y, int radius) const {
    std::vector<std::tuple<int, int>> selected;
    double radiusSquared = radius * radius;

    for (int i = std::max(0, y - radius); i < std::min(height, y + radius); ++i) {
        for (int j = std::max(0, x - radius); j < std::min(width, x + radius); ++j) {
            if (distanceSquared(x, y, j, i) <= radiusSquared) {
                selected.emplace_back(j, i);
            }
        }
    }
    return selected;
}
