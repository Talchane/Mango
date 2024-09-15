#ifndef ENNEMY_HPP
#define ENNEMY_HPP

#include "Fonctions.hpp"
#include "raylib.h"
#include "Clock.hpp"
#include "Personnage.hpp"
#include "Texture_loader.hpp"
#include "Circle.hpp"
#include "Stats.hpp"
#include <string>
#include <vector>


class Ennemy
{
public:
    Ennemy(const Color& _color_, const Texture2D& _tex_);

    // Méthode virtuelle pour permettre l'héritage et la surcharge
    bool actualize(Personnage &player, const float dt);

    // Méthode qui inflige des dégats à l'ennemi. Renvoie true si l'ennemi est mort de ses dégats.
    bool toucher(const Ball& balle);

    // Méthode pour dessiner l'ennemi, marquée comme const car elle ne modifie pas l'état de l'objet
    void Draw() const;

    Circle colCircle;

private:

    void placementAleatoire();

    Color color;
    Vector2 position;
    int life;
    float speed;
    Texture2D texture;
    float scale;
};

#endif // ENNEMY_HPP
