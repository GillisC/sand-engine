#pragma once 

#include <SDL2/SDL.h>
#include "color.h"

class Grid;

// Base class for all elements
class Element {
public:
    Color color;

    Element(Color color) : color(color) {}

    virtual void update(Grid& grid, int x, int y) = 0;
    
    // Default rendering
    virtual void display(SDL_Renderer* renderer, int x, int y) {
        SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        SDL_RenderDrawPoint(renderer, x, y);
    }
    

    virtual ~Element() = default;

};