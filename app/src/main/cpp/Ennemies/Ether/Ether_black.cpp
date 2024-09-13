//
// Created by benfe on 14/09/2024.
//

#include "Ether_black.hpp"

EtherBlack::EtherBlack(Texture2D &_tex_)
{
    tex = _tex_;

    placementAleatoire();

    colCircle.radius = 20;
}

void EtherBlack::actualize(Personnage &player, const float dt)
{
    //------------- Déplacement ---------

    Vector2 diff = player.position;
    diff.x -= position.x;
    diff.y -= position.y;

    diff = rendreUnitaire(diff);

    position.x += diff.x * speed;
    position.y += diff.y * speed;

    colCircle.position = position;

    // ------------- Attaque -----------
}

void EtherBlack::Draw(bool debug) const
{
    DrawTexture(tex, position.x, position.y, WHITE);
    colCircle.Draw();
}
