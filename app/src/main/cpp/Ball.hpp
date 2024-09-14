#ifndef MANGO_BALL_HPP
#define MANGO_BALL_HPP

#include "raylib.h"
#include "cmath"
#include "Collision_circle.hpp"

class Ball
{
public:
    Ball(Vector2 _pos_, float _rot_);
    void actualize(const float dt);
    void Draw(bool debug) const;

    Vector2 position;
    float rotation;
    float speed;
    float damages;
    CollisionCircle colCircle;
};

#endif // BALL_HPP
