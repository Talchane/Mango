#include "Ball.hpp"

Ball::Ball(Vector2 _pos_, float _rot_) : position(_pos_), rotation(_rot_), speed(1000)
{

}

void Ball::actualize(const float dt)
{
    position.x += cos(rotation) * speed * dt;
    position.y += sin(rotation) * speed * dt;
}

// Méthode Draw
void Ball::Draw() const
{
    DrawCircle(position.x, position.y, 10, BLUE);
}
