#include "Ball.hpp"

Ball::Ball(Vector2 _pos_, float _rot_) : position(_pos_), rotation(_rot_), damages(20), speed(1000)
{
    colCircle.position = position;
    colCircle.radius = 10;
}

void Ball::actualize(const float dt)
{
    position.x += cos(rotation) * speed * dt;
    position.y += sin(rotation) * speed * dt;

    colCircle.position = position;
}

// Méthode Draw
void Ball::Draw(bool debug) const
{
    DrawCircle(position.x, position.y, 10, BLUE);
    if (debug)
        colCircle.Draw();

}
