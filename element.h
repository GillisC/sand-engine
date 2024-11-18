#pragma once 

#include <SDL2/SDL.h>
#include "color.h"
#include "utils.h"

class Grid;

// Base class for all elements
class Element {
public:

    Element(Color color) : color(color) {}
    virtual ~Element() = default;

    virtual void update(Grid& grid, int x, int y) = 0;
    
    // Default rendering
    virtual void display(SDL_Renderer* renderer, int x, int y, int pixelSize) {
        Color elementColor = getColor();
        SDL_SetRenderDrawColor(renderer, elementColor.getRed(), elementColor.getGreen(), elementColor.getBlue(), elementColor.getAlpha());
        if (pixelSize == 1) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
        else {
            SDL_Rect rect = { x * pixelSize, y * pixelSize, pixelSize, pixelSize };
            SDL_RenderFillRect(renderer, &rect);
        }
        
    }

    virtual Color getColor() const { return color; }

    virtual bool isLiquid() const { return false; }
    virtual bool isSolid() const { return false; }
    virtual bool isGas() const { return false; }
    virtual bool isFlammable() const { return false; }
    virtual bool isAir() const { return false; }


private:
    Color color;
    

};