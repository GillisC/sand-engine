#pragma once

#include <random>


inline double randomReal(double rangeStart = 0.0, double rangeEnd = 1.0) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(rangeStart, rangeEnd); 

    return dist(rng);
}

inline int randomInt(int rangeStart, int rangeEnd) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(rangeStart, rangeEnd);

    return dist(rng);
}