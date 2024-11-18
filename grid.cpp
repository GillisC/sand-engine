#include "grid.h"

Grid::Grid(int w, int h, int pixelSize)
    : gridWidth(int(w / pixelSize)), gridHeight(int(h / pixelSize)), windowWidth(w), windowHeight(h), pixelSize(pixelSize) {
    std::cout << "Constructor called with width: " << gridWidth << ", height: " << gridHeight << std::endl;

    // Initialize the grid
    air = std::make_shared<Air>(); // All air cells share the same instance of air
    grid = std::vector<std::vector<std::shared_ptr<Element>>>(gridHeight, std::vector<std::shared_ptr<Element>>(gridWidth, air));

    std::cout << "Grid initialized with dimensions: " << gridWidth << " x " << gridHeight << std::endl;
    std::cout << "grid.size(): " << grid.size() << std::endl;
    if (!grid.empty()) {
        std::cout << "grid[0].size(): " << grid[0].size() << std::endl;
    }
}

// Clears the grid
void Grid::clear() {
    grid.assign(gridHeight, std::vector<std::shared_ptr<Element>>(gridWidth, air));
}

void Grid::set(int x, int y, std::shared_ptr<Element> element) {
    if (isInBounds(x, y)) {
        grid[y][x] = element;
    }
    else {
        std::cerr << "Out of bounds, trying to insert element into: (" << x << ", " << y << ")" << std::endl;
    }
}

std::shared_ptr<Element> Grid::get(int x, int y) const {
    if (isInBounds(x, y)) {
        return grid[y][x];
        std::cout << grid[y][x] << std::endl;
    }
    else {
        std::cerr << "Out of bounds, trying to get element at: (" << x << ", " << y << ")" << std::endl;
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

void Grid::remove(int x, int y) {
    if (isInBounds(x, y)) {
        grid[y][x] = air;
    }
}

bool Grid::isEmpty(int x, int y) const {
    if (isInBounds(x, y)) {
        return get(x, y)->isAir();
    }
    else {
        std::cerr << "Out of bounds, trying to check if cell is empty at: (" << x << ", " << y << ")" << std::endl;
    }
    return false;
}

bool Grid::isLiquid(int x, int y) const {
    if (isInBounds(x, y)) {
        return get(x, y)->isLiquid();
    }
}


void Grid::updateElements() {
    // Go backwards through the grid to not update the same cell more than once
    for (int i = gridHeight - 1; i >= 0; i--) {
        for (int j = gridWidth - 1; j >= 0; j--) {
            auto element = get(j, i);
            if (!element) {
                std::cerr << "Null pointer at (" << j << ", " << i << ")\n";
                continue;
            }
            if ( !(element->isAir())) {
                get(j, i)->update(*this, j, i);
            }
        }
    }
}

void Grid::displayElements(SDL_Renderer* renderer) const {
    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            auto element = get(j, i);
            if (!element) {
                std::cerr << "Null pointer at (" << j << ", " << i << ")\n";
                continue;
            }
            if ( !(element->isAir()) ) {
                get(j, i)->display(renderer, j, i, pixelSize);
            }
        }
    }
}

int Grid::getGridWidth() const {
    return gridWidth;
}

int Grid::getGridHeight() const {
    return gridHeight;
}

int Grid::getWindowWidth() const {
    return windowWidth;
}

int Grid::getWindowHeight() const {
    return windowHeight;
}

bool Grid::isInBounds(int x, int y) const {
    return x >= 0 && x < gridWidth && y >= 0 && y < gridHeight;
}

double distanceSquared(int x1, int y1, int x2, int y2) {
    return static_cast<double>((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

std::vector<std::tuple<int, int>> Grid::getCircleSelection(int x, int y, int radius, double selectionChance) const {
    std::vector<std::tuple<int, int>> selected;
    double radiusSquared = radius * radius;
    
    int grid_x, grid_y;
    grid_x = x / pixelSize;
    grid_y = y / pixelSize;

    for (int i = std::max(0, grid_y - radius); i < std::min(gridHeight, grid_y + radius); ++i) {
        for (int j = std::max(0, grid_x - radius); j < std::min(gridWidth, grid_x + radius); ++j) {
            if (distanceSquared(grid_x, grid_y, j, i) <= radiusSquared) {
                if (randomReal() < selectionChance) {
                    selected.emplace_back(j, i);
                }
            }
        }
    }
    return selected;
}
