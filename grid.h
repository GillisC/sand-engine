#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "element.h"
#include <SDL2/SDL.h>
#include <string>
#include "utils.h"
#include "air.h"


class Grid {
public:
    // Attributes
    std::vector<std::vector<std::shared_ptr<Element>>> grid;

    // Constructor
    Grid(int windowWidth, int windowHeight, int pixelSize);

    // Methods
    void clear();
    void set(int x, int y, std::shared_ptr<Element> element);
    std::shared_ptr<Element> get(int x, int y) const;
    void swap(int x1, int y1, int x2, int y2);
    void remove(int x, int y);
    bool isEmpty(int x, int y) const;
    bool isLiquid(int x, int y) const;
    void updateElements();
    void displayElements(SDL_Renderer* renderer) const;
    int getGridWidth() const;
    int getGridHeight() const;
    int getWindowWidth() const;
    int getWindowHeight() const;
    std::vector<std::tuple<int, int>> getCircleSelection(int x, int y, int radius, double selectionChance = 1.0) const;
    bool isInBounds(int x, int y) const;

    
private:
    int gridWidth, gridHeight, windowWidth, windowHeight, pixelSize;
    std::shared_ptr<Air> air;

};