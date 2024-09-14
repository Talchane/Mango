#ifndef ENNEMY_HPP
#define ENNEMY_HPP

#include "Fonctions.hpp"
#include "raylib.h"
#include "Clock.hpp"
#include "Personnage.hpp"
#include "Texture_loader.hpp"
#include "Collision_circle.hpp"
#include "Stats.hpp"
#include <string>
#include <vector>


class Ennemy
{
public:
    Ennemy(const Stats& _stats_);

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
    float speedAttack;
    float damages;

    tuple<float, float, float> resistances;

    float rotation;
    CollisionCircle colCircle;
    Texture2D tex;
    float scale;
    Clock clock;

};

#endif // ENNEMY_HPP
