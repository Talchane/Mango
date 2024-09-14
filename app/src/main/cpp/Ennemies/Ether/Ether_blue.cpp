//
// Created by benfe on 14/09/2024.
//


#include "Ether_blue.hpp"

EtherBlue::EtherBlue(Texture2D &_tex_, Stats _stats_) : EtherType(_stats_)
{
    tex = _tex_;

    placementAleatoire();
    colCircle.radius = 20;
}

void EtherBlue::actualize(Personnage &player, const float dt)
{
    //------------- Déplacement ---------

    Vector2 dir = player.position;
    dir.x -= position.x;
    dir.y -= position.y;

    dir = rendreUnitaire(dir);

    position.x += dir.x * speed * dt;
    position.y += dir.y * speed * dt;

    colCircle.position = position;

    // ------------- Attaque -----------
}

void EtherBlue::Draw(bool debug) const
{
    Vector2 drawPosition;
    drawPosition.x = position.x - (TextureLoader::getMobTextureDims().x * scale) / 2;
    drawPosition.y = position.y - (TextureLoader::getMobTextureDims().y * scale) / 2;

    DrawTextureEx(tex, drawPosition, rotation, scale, WHITE);
    if (debug)
        colCircle.Draw();
}
