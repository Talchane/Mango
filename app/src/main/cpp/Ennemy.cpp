#include "Ennemy.hpp"


Ennemy::Ennemy() : scale(0.2f), rotation(0)
{

}

void Ennemy::placementAleatoire()
{
    if (rand() % 2 == 0)    // Haut Bas
    {
        position.x = rand() % GetScreenWidth();
        position.y = rand() % 2 * GetScreenHeight();
    }
    else    // Gauche Droite
    {
        position.x = rand() % 2 * GetScreenWidth();
        position.y = rand() % GetScreenHeight();
    }
    colCircle.position = position;
}
