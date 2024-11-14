#pragma once

#include <iostream>
#include <random>
#include <algorithm>

inline int varyColor(int colorComponent, int variationRange = 20) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-variationRange, variationRange);

    int c_new = colorComponent + distr(gen);
    c_new = std::clamp(c_new, 0, 255);

    return c_new;
}