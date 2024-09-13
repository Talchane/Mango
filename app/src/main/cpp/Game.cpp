#include "Game.hpp"

Game::Game() : inGame(false)
{
    // Vous pouvez initialiser ici si nécessaire
}

void Game::actualize()
{
    if (inGame) // Si on est en partie
    {
        checkSpawn();               // Check apparition des ennemis
        player.actualize();         // Actions du joueur (tirer, changer d'arme), déplacement et animation des balles
        checkCollisionsTirs();      // Check des collisions entre les balles et les ennemis

        for (int i = 0; i < ennemies.size(); ++i)
            ennemies[i]->actualize();   // Actualise les attaques et les animations des ennemis
    }
    else    // On est sur le menu
    {

    }
}

void Game::Draw()
{
    player.Draw();

    for (int i = 0; i < ennemies.size(); ++i)
        ennemies[i]->Draw();
}

void Game::checkSpawn()
{
    // Implémentez la logique de spawn ici
}

void Game::checkCollisionsTirs()
{
    // Implémentez la logique de détection de collisions ici
}
