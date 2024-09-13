#include "Personnage.hpp"

// Constructeur
Personnage::Personnage()
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
void Personnage::actualize()
{
    // Implémentez la logique de mise à jour ici
}
