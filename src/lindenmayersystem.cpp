#include "lindenmayersystem.h"
#include <fstream>
#include <iostream>
#include <sstream>

LindenmayerSystem::LindenmayerSystem(const std::string& name,
                                     const int degrees,
                                     const std::string& start,
                                     const std::map<const char, const std::string>& productions) :
    name(name), degrees(degrees), initialWord(start), productions(productions)
{}

// Replaces a symbol by its production. Helper function of produceNextWord.
std::string LindenmayerSystem::replaceSymbol(const char symbol)
{
    auto iter = this->productions.find(symbol);
    if (iter != this->productions.end())
        return iter->second;
    return std::string(1, symbol);
}

// Given the current word it returns the next word. Helper function of produceNthWord.
std::string LindenmayerSystem::produceNextWord(const std::string& word)
{
    std::stringstream stream;
    for (const char& symbol : word) {
        stream << replaceSymbol(symbol);
    }
    std::string result = stream.str();
    return result;
}

// Computes the resulting word after N iterations
std::string LindenmayerSystem::produceNthWord(const int iterations)
{
    std::string nthWord = this->initialWord;
    for (int i=0; i<iterations; ++i) {
        nthWord = produceNextWord(nthWord);
    }
    return nthWord;
}

std::vector<std::vector<Point2D>> LindenmayerSystem::evaluateWord(const std::string& word)
{
    std::vector<std::vector<Point2D>> paths(1);
    std::stack<Point2D> continuationStack;

    Turtle turtle;
    for(const char c : word)
    {
        if(isupper(c))
        {
            if(paths.back().empty())
                paths.back().emplace_back(turtle.getPosition());
            turtle.move();
            paths.back().emplace_back(turtle.getPosition());
        }
        else
        {
            switch(c)
            {
            case 'f':
                turtle.move();
                if(!paths.back().empty())
                    paths.emplace_back();
                break;
            case '+':
                turtle.turn(-degrees);
                break;
            case '-':
                turtle.turn(degrees);
                break;
            case '|':
                turtle.turn(180);
                break;
            case '[':
                turtle.save();
                continuationStack.emplace(turtle.getPosition());
                break;
            case ']':
                turtle.restore();
                paths.emplace_back(1, continuationStack.top());
                continuationStack.pop();
                break;
            }
        }
    }
    return paths;
}

void LindenmayerSystem::generateSVGImages(const int beginIteration, const int endIteration)
{
    std::string word = produceNthWord(beginIteration);
    for(int iteration = beginIteration; iteration <= endIteration; ++iteration)
    {
        std::vector<std::vector<Point2D>> paths = evaluateWord(word);

        BoundingBox boundingBox;
        for(const std::vector<Point2D>& path : paths)
            for(const Point2D& point : path)
                boundingBox.includePoint(point);

        SVGImage image(boundingBox);
        for(const std::vector<Point2D>& path : paths)
            image.addPath(path);

        std::ofstream os(std::string("results/") + name + "_" + std::to_string(iteration) + ".svg");
        os << image;
        os.close();

        word = produceNextWord(word);
    }
}

void LindenmayerSystem::generateSVGImage(const int iteration)
{
    generateSVGImages(iteration, iteration);
}

