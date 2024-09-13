#ifndef BALL_HPP
#define BALL_HPP

#include "raylib.h"
#include "cmath"

class Ball
{
public:
    Ball(Vector2 _pos_, float _rot_);
    void actualize(const float dt);
    void Draw() const;

    Vector2 position;
    float rotation;
    float speed;
};

#endif // BALL_HPP
