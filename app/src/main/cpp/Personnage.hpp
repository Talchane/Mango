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
    void actualize();

private:
    std::vector<Ball*> balles;
};

#endif // PERSONNAGE_HPP
