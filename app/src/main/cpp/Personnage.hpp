#ifndef MANGO_PERSONNAGE_HPP
#define MANGO_PERSONNAGE_HPP

#include <vector>       // Pour std::vector
#include "Ball.hpp"    // Assurez-vous que ce fichier existe et est accessible
#include "Clock.hpp"
#include "raylib.h"    // Pour raylib, si vous utilisez ses fonctions comme DrawCircle
#include "Collision_circle.hpp"

class Personnage
{
public:
    Personnage(const Vector2 ScreenDims);

    void Draw(bool debug) const;
    void actualize(const float dt);

    Vector2 position;
    vector<Ball*> balles;
private:
    CollisionCircle colCircle;
    float rotation;
    Clock clockTir;
};

#endif // PERSONNAGE_HPP
