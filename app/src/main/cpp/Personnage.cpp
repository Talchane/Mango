#include "Personnage.hpp"

// Constructeur
Personnage::Personnage() : rotation(0)
{
    // Initialisez ici si nécessaire
}

// Méthode Draw
void Personnage::Draw()
{
    for (int i = 0; i < balles.size(); ++i)
        balles[i]->Draw();

    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, RED);
}

// Méthode actualize
void Personnage::actualize(const float dt)
{
    // ---------- Check actions -------------

    // --- Check tir ---
    int touchCount = GetTouchPointCount();
    if (touchCount > 0)
    {
        Vector2 touchPosition { GetTouchPosition(0) };

        rotation = atan2(touchPosition.x - position.x, touchPosition.y - position.y);
        balles.push_back(new Ball(position, rotation)); // On crée une nouvelle balle
    }

    // Check changement d'arme / de balle

    // ------- Actualisation des balles -----
    for (int i = 0; i < size(balles); ++i) {
        balles[i] -> actualize(dt);
    }

}
