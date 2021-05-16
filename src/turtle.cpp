#include "turtle.h"

// TODO: Add code here

Turtle::Turtle() : state(), stack() {}

const Point2D& Turtle::getPosition() const
{
    return this->state.position;
}

void Turtle::move(const int steps)
{
    this->state.position.x += steps * this->state.direction.x;
    this->state.position.y += steps * this->state.direction.y;
}

void Turtle::move()
{
    this->move(1);
}

void Turtle::turn(const int degrees)
{
    this->state.direction.rotate(static_cast<double>(degrees));
}

void Turtle::save()
{
    this->stack.push(this->state);
}

void Turtle::restore()
{
    if (!this->stack.empty()) {
        this->state = this->stack.top();
        this->stack.pop();
    }
}
