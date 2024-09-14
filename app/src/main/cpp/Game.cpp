#include "Game.hpp"

Game::Game(Vector2 const& ScreenDims) : inGame(false),
                                        player(ScreenDims),
                                        startButton(ScreenDims.x / 2, ScreenDims.y / 2, 150, 150, "Start")
{
    textures.loadAll();
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
            level.loadLvl(1);
            inGame = true;
            clockLevel.restart();
        }
    }
}

void Game::Draw()
{
    if (inGame)
    {
        player.Draw(true);

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
     */
    if (level.ended())
        return;

    if (clockLevel.getElapsedTime() > level.getNextTimeCode())
    {
        for (int i = 0; i < level.getNextQuantity(); ++i)
        {
            string newType(level.getNextType());

            if (newType == "Ether_black")
                ennemies.push_back(new EtherBlack(textures.texEtherBlack));
            else
            {
                LOGE("Error Game.cpp : unknown mob level : %d, type : %s", level.numlvl, newType.c_str());
                exit(1);
            }
        }
        level.nextStep();

        // ----- Check fin niveau ---------
        if (level.ended())
        {
            //  --------- Niveau vient de se terminer ----------
        }
    }
}

void Game::checkCollisionsTirs()
{
    // Implémentez la logique de détection de collisions ici
}
