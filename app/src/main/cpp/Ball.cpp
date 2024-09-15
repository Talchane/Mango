#include "Ball.hpp"

Ball::Ball(Vector2 _pos_, float _rot_, Color _color_) : position(_pos_), rotation(_rot_), speed(1000), color(_color_)
{
    colCircle.position = position;
    colCircle.radius = 10;
    colCircle.color = color;
}

void Ball::actualize(const float dt)
{
    position.x += cos(rotation) * speed * dt;
    position.y += sin(rotation) * speed * dt;

    colCircle.position = position;
}

// Méthode Draw
void Ball::Draw() const
{
    colCircle.Draw();
}
