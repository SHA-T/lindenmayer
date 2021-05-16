#include "boundingbox.h"
#include <cmath>

int BoundingBox::minX() const { return static_cast<int>(std::floor(lowerLeft.x)); }
int BoundingBox::minY() const { return static_cast<int>(std::floor(lowerLeft.y)); }
int BoundingBox::maxX() const { return static_cast<int>(std::ceil(upperRight.x)); }
int BoundingBox::maxY() const { return static_cast<int>(std::ceil(upperRight.y)); }

int BoundingBox::width()  const { return maxX() - minX(); }
int BoundingBox::height() const { return maxY() - minY(); }

void BoundingBox::includePoint(const Point2D& p)
{
    if(p.x < lowerLeft.x)
        lowerLeft.x = p.x;
    else if(p.x > upperRight.x)
        upperRight.x = p.x;

    if(p.y < lowerLeft.y)
        lowerLeft.y = p.y;
    else if(p.y > upperRight.y)
        upperRight.y = p.y;
}

