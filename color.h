#pragma once

#include <iostream>
#include <random>
#include <algorithm>

class Color {
public:
    Color(int r, int g, int b, int a) :
        r(r), g(g), b(b), a(a) {}

    int getRed() const { return r; }
    int getGreen() const { return g; }
    int getBlue() const { return b; }
    int getAlpha() const { return a; }

    void setColor(Color color) {
        r = color.getRed();
        g = color.getGreen();
        b = color.getBlue();
        a = color.getAlpha();
    }

    void setRed(int red) { r = red; }
    void setGreen(int green) { g = green; }
    void setBlue(int blue) { b = blue; }
    void setAlpha(int alpha) { a = alpha; }

private:
    int r, g, b, a;
};


inline Color varyColor(Color color, int variationRange = 20) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-variationRange, variationRange);

    int r_new = color.getRed() + distr(gen);
    r_new = std::clamp(r_new, 0, 255);

    int g_new = color.getGreen() + distr(gen);
    g_new = std::clamp(g_new, 0, 255);

    int b_new = color.getBlue() + distr(gen);
    b_new = std::clamp(b_new, 0, 255);

    return Color(r_new, g_new, b_new, color.getAlpha());
}