//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_CIRCLE_HPP
#define MANGO_CIRCLE_HPP

#include "raylib.h"
#include "Fonctions.hpp"

using namespace std;

struct Circle
{
    Circle();
    Circle(const Vector2& _pos_, const float _rad_, Color _color_);
    Vector2 position;
    float radius;
    Color color;

    void Draw() const;
};

bool collisionCercleCercle(const Circle& C1, const Circle& C2);


#endif //MANGO_CIRCLE_HPP
