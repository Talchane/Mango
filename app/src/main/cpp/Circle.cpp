//
// Created by benfe on 14/09/2024.
//

#include "Circle.hpp"

Circle::Circle()
{}

Circle::Circle(const Vector2 &_pos_, const float _rad_, Color _color_) : position(_pos_), radius(_rad_), color(_color_)
{}

void Circle::Draw() const
{
    DrawCircleV(position, radius, color); // Dessiner le cercle de collision
}

bool collisionCercleCercle(const Circle& C1, const Circle& C2)
{
    return (distance(C2.position, C1.position) <= (C1.radius + C2.radius));
}