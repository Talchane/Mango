#include "Personnage.hpp"

// Constructeur
Personnage::Personnage(const Vector2 ScreenDims) : rotation(0), position({ScreenDims.x / 2, ScreenDims.y / 2})
{
    colCircle.position = position;
    colCircle.radius = 100;
}

// Méthode Draw
void Personnage::Draw(bool debug) const
{
    for (int i = 0; i < balles.size(); ++i)
        balles[i]->Draw(debug);

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

            rotation = atan2(touchPosition.x - position.x, touchPosition.y - position.y);
            balles.push_back(new Ball(position, rotation)); // On crée une nouvelle balle
            clockTir.restart();
        }
    }

    // Check changement d'arme / de balle

    // ------- Actualisation des balles -----
    for (int i = 0; i < size(balles); ++i) {
        balles[i] -> actualize(dt);
    }

}
