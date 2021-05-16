#ifndef SVGIMAGE_H
#define SVGIMAGE_H

#include <string>
#include <vector>
#include "boundingbox.h"
#include "geometry.h"

class SVGImage
{
private:
    const BoundingBox boundingBox;
    std::string content;

public:
    SVGImage(const BoundingBox& boundingBox);

    void addPath(const std::vector<Point2D>& points);

    friend std::ostream& operator<<(std::ostream& os, const SVGImage& svg);
};

#endif // SVGIMAGE_H

