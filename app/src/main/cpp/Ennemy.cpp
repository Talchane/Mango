#include "Ennemy.hpp"

CollisionCircle::CollisionCircle()
{}

CollisionCircle::CollisionCircle(const Vector2 &_pos_, const float _rad_) : position(_pos_), radius(_rad_)
{}

void CollisionCircle::Draw() const
{
    DrawCircleV(position, radius, (Color){255, 50, 50, 150}); // Dessiner le cercle de collision
}


Ennemy::Ennemy()
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
