#include "Game.hpp"

Game::Game(Vector2 const& ScreenDims) : inGame(false),
                                        player(ScreenDims),
                                        startButton(ScreenDims.x / 2, ScreenDims.y / 2, 150, 150, "Start"),
                                        indexSpawn(0)
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
            ennemies[i]->actualize(player, dt);   // Actualise les attaques et les animations des ennemis
    }
    else    // On est sur le menu
    {
        if (startButton.isPressed())
        {
            levelData = readLevel(1);
            inGame = true;
            clockLevel.restart();
        }
    }
}

void Game::Draw()
{
    if (inGame)
    {
        player.Draw();

        for (int i = 0; i < ennemies.size(); ++i)
            ennemies[i]->Draw(true);
    }
    else
    {
        startButton.Draw();
    }
}

void Game::checkSpawn()
{
    /*
     * get<0> est le float de l'horaire de spawn
     * get<1> est l'int de la quantité à spawn
     * get<2> est la string du type de mob
     *//*
    if (clockLevel.getElapsedTime() > get<0>(levelData[indexSpawn]))
    {
        for (int i = 0; i < get<1>(levelData[indexSpawn]); ++i)
            ennemies.push_back(new EtherBlack(texEtherBlack));

        indexSpawn++;
    }*/
}

void Game::checkCollisionsTirs()
{
    // Implémentez la logique de détection de collisions ici
}
