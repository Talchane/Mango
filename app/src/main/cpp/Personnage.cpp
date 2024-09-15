#include "Personnage.hpp"

// Constructeur
Personnage::Personnage(const Vector2 ScreenDims) : life(3), rotation(0), shootColor(RED), position({ScreenDims.x / 2, ScreenDims.y / 2})
{
    colCircle.position = position;
    colCircle.radius = 100;
    setColor((Color){255, 0, 0, 255});
}

// Méthode Draw
void Personnage::Draw(bool debug) const
{
    for (int i = 0; i < balles.size(); ++i)
        balles[i].Draw();

    if (debug)
        colCircle.Draw();
}

// Méthode actualize
void Personnage::actualize(const float dt)
{
    // ---------- Check actions -------------

    // --- Check tir ---
    if (clockTir.getElapsedTime() > 0.1f)
    {
        int touchCount = GetTouchPointCount();
        if (touchCount > 0)
        {
            Vector2 touchPosition{GetTouchPosition(0)};

            rotation = M_PI / 2.f - atan2(touchPosition.x - position.x, touchPosition.y - position.y);
            balles.emplace_back(position, rotation, shootColor); // On crée une nouvelle balle
            clockTir.restart();
        }
    }

    // Check changement d'arme / de balle

    // ------- Actualisation des balles -----
    for (int i = 0; i < size(balles); ++i) {
        balles[i].actualize(dt);
    }
}

void Personnage::setColor(const Color& col)
{
    shootColor = col;
    colCircle.color = col;
}
