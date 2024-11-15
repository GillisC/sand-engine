#pragma once 

#include <SDL2/SDL.h>
#include "color.h"

class Grid;

// Base class for all elements
class Element {
public:
    Color color;

    Element(Color color) : color(color) {}
    virtual ~Element() = default;

    virtual void update(Grid& grid, int x, int y) = 0;
    
    // Default rendering
    virtual void display(SDL_Renderer* renderer, int x, int y, int pixelSize) {
        SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        if (pixelSize == 1) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
        else {
            SDL_Rect rect = { x * pixelSize, y * pixelSize, pixelSize, pixelSize };
            SDL_RenderFillRect(renderer, &rect);
        }
        
    }

    virtual bool isLiquid() const { return false; }
    virtual bool isSolid() const { return false; }
    virtual bool isGas() const { return false; }
    

    

};