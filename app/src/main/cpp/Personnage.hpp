#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <vector>       // Pour std::vector
#include "Ball.hpp"    // Assurez-vous que ce fichier existe et est accessible
#include "raylib.h"    // Pour raylib, si vous utilisez ses fonctions comme DrawCircle

class Personnage
{
public:
    Personnage();

    void Draw();
    void actualize(const float dt);

private:
    std::vector<Ball*> balles;
    float rotation;
    Vector2 position;
};

#endif // PERSONNAGE_HPP
