#include "Ennemy.hpp"


Ennemy::Ennemy(const Stats& _stats_) : scale(0.2f), rotation(0)
{
    type = _stats_.type;
    life = _stats_.life;
    speed = _stats_.speed;
    speedAttack = _stats_.speedAttack;

    resistances = _stats_.resistances;

    colCircle.radius = 30;
}

bool Ennemy::blesser(Ball *balle)
{
    life -= balle -> damages;
    if (life < 0)
    {
        // MORT
        return true;
    }
    return false;
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
