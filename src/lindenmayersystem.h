#ifndef LINDENMAYERSYSTEM_H
#define LINDENMAYERSYSTEM_H

#include <map>
#include <string>
#include <vector>
#include "boundingbox.h"
#include "turtle.h"
#include "svgimage.h"

using Production = std::pair<const char, const std::string>;

class LindenmayerSystem
{
private:
    const std::string name;
    const int degrees;
    const std::string initialWord;
    const std::map<const char, const std::string> productions;

    std::string replaceSymbol(const char symbol);
    std::string produceNextWord(const std::string& word);
    std::string produceNthWord(const int iterations);

    std::vector<std::vector<Point2D>> evaluateWord(const std::string& word);

public:
    LindenmayerSystem(const std::string& name,
                      const int degrees,
                      const std::string& initialWord,
                      const std::map<const char, const std::string>& productions);

    void generateSVGImages(const int beginIteration, const int endIteration);
    void generateSVGImage(const int iteration);
};

#endif // LINDENMAYERSYSTEM_H

