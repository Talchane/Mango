#include "Game.hpp"
#include "raylib.h"

Game::Game(Vector2 const& ScreenDims) : inGame(false),
               startButton(ScreenDims.x / 2, ScreenDims.y / 2, 150, 150, "Start")
{
    // Vous pouvez initialiser ici si nécessaire
}

void Game::actualize(const float dt)
{
    if (inGame) // Si on est en partie
    {
        checkSpawn();               // Check apparition des ennemis
        player.actualize(dt);       // Actions du joueur (tirer, changer d'arme), déplacement et animation des balles
        checkCollisionsTirs();      // Check des collisions entre les balles et les ennemis

        for (int i = 0; i < ennemies.size(); ++i)
            ennemies[i]->actualize(dt);   // Actualise les attaques et les animations des ennemis
    }
    else    // On est sur le menu
    {
        if (startButton.isPressed())
            inGame = true;
    }
}

void Game::Draw()
{
    if (inGame)
    {
        player.Draw();

        for (int i = 0; i < ennemies.size(); ++i)
            ennemies[i]->Draw();
    }
    else
    {
        startButton.Draw();
    }
}

void Game::checkSpawn()
{
    // Implémentez la logique de spawn ici
}

void Game::checkCollisionsTirs()
{
    // Implémentez la logique de détection de collisions ici
}
