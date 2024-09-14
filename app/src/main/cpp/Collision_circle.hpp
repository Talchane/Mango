//
// Created by benfe on 14/09/2024.
//

#ifndef MANGO_COLLISION_CIRCLE_HPP
#define MANGO_COLLISION_CIRCLE_HPP

#include "raylib.h"

using namespace std;

struct CollisionCircle
{
    CollisionCircle();
    CollisionCircle(const Vector2& _pos_, const float _rad_);
    Vector2 position;
    float radius;

    void Draw() const;
};


#endif //MANGO_COLLISION_CIRCLE_HPP
