#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "geometry.h"

class BoundingBox
{
private:
    Point2D lowerLeft;
    Point2D upperRight;

public:
    BoundingBox(): lowerLeft(), upperRight() {}

    int minX() const;
    int minY() const;
    int maxX() const;
    int maxY() const;

    int width() const;
    int height() const;

    void includePoint(const Point2D& p);
};

#endif // BOUNDINGBOX_H

