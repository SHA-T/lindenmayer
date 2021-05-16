#include "svgimage.h"
#include <sstream>

SVGImage::SVGImage(const BoundingBox& boundingBox) :
    boundingBox(boundingBox)
{}

void SVGImage::addPath(const std::vector<Point2D>& points)
{
    if(points.empty())
        return;
    std::stringstream ss;
    ss << "<path d=\"M" << points.front().x << " " << points.front().y;
    for(const Point2D& point : points)
        ss << " L" << point.x << " " << point.y;
    ss << "\"/>\n";
    content += ss.str();
}

std::ostream& operator<<(std::ostream& os, const SVGImage& svg)
{
    const int x = svg.boundingBox.minX() - 10;
    const int y = svg.boundingBox.minY() - 10;
    const int w = svg.boundingBox.width() + 20;
    const int h = svg.boundingBox.height() + 20;
    os << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    os << "<svg xmlns=\"http://www.w3.org/2000/svg\"\n";
    os << " version=\"1.1\" baseProfile=\"basic\"\n";
    os << " viewBox=\"" << x << " " << y << " " << w << " " << h << "\"\n";
    os << " width=\"" << 1280 << "px\" height=\"" << 1024 << "px\"\n stroke=\"white\" stroke-width=\"1px\"\n fill=\"black\" fill-opacity=\"0\">\n";
    os << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << w << "\" height=\"" << h << "\" stroke-width=\"0px\" fill-opacity=\"1\"/>\n";
    os << svg.content;
    os << "</svg>\n";
    return os;
}

