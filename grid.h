#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "element.h"
#include <SDL2/SDL.h>
#include <string>

class Grid {
public:
    // Attributes
    std::vector<std::vector<std::shared_ptr<Element>>> grid;

    // Constructor
    Grid(int width, int height);

    // Methods
    void clear();
    void set(int x, int y, std::shared_ptr<Element> element);
    void swap(int x1, int y1, int x2, int y2);
    bool isEmpty(int x, int y) const;
    void updateElements();
    void displayElements(SDL_Renderer* renderer) const;
    int getWidth() const;
    int getHeight() const;
    std::vector<std::tuple<int, int>> getCircleSelection(int x, int y, int radius) const;
    std::string toString() const;
    bool isInBounds(int x, int y) const;

private:
    int width, height;

    
};