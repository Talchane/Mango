#ifndef MANGO_BALL_HPP
#define MANGO_BALL_HPP

#include "raylib.h"
#include "cmath"
#include "Circle.hpp"

class Ball
{
public:
    Ball(Vector2 _pos_, float _rot_, Color _color_);
    void actualize(const float dt);
    void Draw() const;

    Vector2 position;
    Color color;
    float rotation;
    float speed;
    Circle colCircle;
};

#endif // BALL_HPP
