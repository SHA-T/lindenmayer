#ifndef TURTLE_H
#define TURTLE_H

#include <stack>
#include "geometry.h"

struct State
{
    Point2D position;
    Vector2D direction;

    State() : position(0, 0), direction(5, 0) {}
};

class Turtle
{
    // TODO: Add code here
private:
    State state;
    std::stack<State> stack;
public:
    Turtle();

    const Point2D& getPosition() const;
    void move(const int steps);
    void move();
    void turn(const int degrees);
    void save();
    void restore();
};

#endif // TURTLE_H

