#include "Ennemy.hpp"


Ennemy::Ennemy(const Color& _color_, const Texture2D& _tex_) : color(_color_), life(1), speed(100), texture(_tex_), scale(0.2f)
{
    colCircle.radius = 50;
    placementAleatoire();
}

// Return true si le cercle est mort
bool Ennemy::actualize(Personnage &player, const float dt)
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

    if (collisionCercleCercle(colCircle, player.colCircle))
    {
        player.life--;
        return true;;
    }
    return false;
}

bool Ennemy::toucher(const Ball& balle)
{

    LOGE("Ennemy : R = %d, G = %d, B = %d", color.r, color.g, color.b);
    LOGE("Balle : R = %d, G = %d, B = %d", balle.color.r, balle.color.g, balle.color.b);
    // Si c'est pas la même couleur, aucun effet.
    if (!(balle.color == color))
        return false;

    life--;
    if (life == 0)
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

void Ennemy::Draw() const
{
    //colCircle.Draw();

    Vector2 spriteSize = { (float)texture.width * scale, (float)texture.height * scale };
    Vector2 centerPosition =  (Vector2){position.x - spriteSize.x / 2, position.y - spriteSize.y / 2};

    DrawTextureEx(texture, centerPosition, 0.0f, scale, color);
}