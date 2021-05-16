#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Vector2D
{
    double x;
    double y;

    Vector2D() : x(0), y(0) {}
    Vector2D(const double x, const double y) : x(x), y(y) {}

    void rotate(const double degrees);
};

using Point2D = Vector2D;

#endif // GEOMETRY_H

