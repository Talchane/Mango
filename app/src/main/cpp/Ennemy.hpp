#ifndef ENNEMY_HPP
#define ENNEMY_HPP

#include "Fonctions.hpp"
#include "raylib.h"
#include "Clock.hpp"
#include "Personnage.hpp"
#include <string>
#include <vector>

using namespace std;

struct CollisionCircle
{
    CollisionCircle();
    CollisionCircle(const Vector2& _pos_, const float _rad_);
    Vector2 position;
    float radius;

    void Draw() const;
};

class Ennemy
{
public:
    Ennemy();

    // Méthode virtuelle pour permettre l'héritage et la surcharge
    virtual void actualize(Personnage &player, const float dt) = 0;

    // Méthode pour dessiner l'ennemi, marquée comme const car elle ne modifie pas l'état de l'objet
    virtual void Draw(bool debug) const = 0;

protected:

    void placementAleatoire();

    Vector2 position;
    string type;
    float life;
    float speed;
    float damages;

    CollisionCircle colCircle;
    Texture2D tex;
    Clock clock;

};

#endif // ENNEMY_HPP
