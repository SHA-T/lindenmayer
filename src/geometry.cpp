#include "geometry.h"
#include <cmath>

constexpr double Pi() { return std::atan(1) * 4; }

void Vector2D::rotate(const double degrees)
{
    const double radians = degrees * Pi() / 180.0;
    const double nx = std::cos(radians) * x - std::sin(radians) * y;
    const double ny = std::sin(radians) * x + std::cos(radians) * y;
    x = nx;
    y = ny;
}

