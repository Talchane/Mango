#include "Game.hpp"

Game::Game(Vector2 const& ScreenDims) : inGame(false),
                                        player(ScreenDims),
                                        startButton(ScreenDims.x / 2, ScreenDims.y / 2, 150, 150, BLUE, "Start")
{
    textures.loadAll();

    for (int i = 0; i < size(colorButtons); ++i)
        colorButtons[i] = Bouton(ScreenDims.x / 2 - 150 + i * 150, ScreenDims.y - 150, 100, 100, RED, "");

    colorButtons[0].buttonColor = {255, 0, 0, 255};
    colorButtons[1].buttonColor = {0, 255, 0, 255};
    colorButtons[2].buttonColor = {0, 0, 255, 255};

    correspondances["Red"] = (Color){255, 0, 0, 255};
    correspondances["Green"] = (Color){0, 255, 0, 255};
    correspondances["Blue"] = (Color){0, 0, 255, 255};

}

void Game::actualize(const float dt)
{
    if (inGame) // Si on est en partie
    {
        checkSpawn();               // Check apparition des ennemis
        player.actualize(dt);       // Actions du joueur (tirer, changer d'arme), déplacement et animation des balles
        checkCollisionsTirs();      // Check des collisions entre les balles et les ennemis

        for (int i = 0; i < ennemies.size(); ++i)
        {
            // Si actualize renvoie true, alors il a touché le joueur et il faut le détruire.
            if (ennemies[i].actualize(player, dt))   // Déplacement de l'ennemi et test collision joueur
            {
                removeElement(ennemies, i);
                i--;
            }
        }
        for (int i = 0; i < size(colorButtons); ++i)
        {
            if (colorButtons[i].isPressed())
                player.setColor(colorButtons[i].buttonColor);
        }
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
            ennemies[i].Draw();
        for (int i = 0; i < size(colorButtons); ++i)
            colorButtons[i].Draw(colorButtons[i].buttonColor == player.shootColor);
    }
    else
    {
        startButton.Draw(false);
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

            ennemies.emplace_back(correspondances[newType], textures.texAnneau80);
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
    for (int i = 0; i < player.balles.size(); ++i)  // Utiliser .size() pour la lisibilité
    {
        bool balleSupprimee = false;  // Marqueur pour savoir si la balle a été supprimée
        for (int j = 0; j < ennemies.size(); ++j)
        {
            if (collisionCercleCercle(player.balles[i].colCircle, ennemies[j].colCircle))
            {
                // Si l'ennemi est touché et meurt
                if (ennemies[j].toucher(player.balles[i]) == true)
                    removeElement(ennemies, j);   // Supprime l'ennemi

                // Supprimer la balle
                removeElement(player.balles, i);  // Supprime la balle à l'index i
                balleSupprimee = true;            // Marquer que la balle est supprimée
                --i;                              // Ajuster l'indice i pour ne pas sauter d'éléments

                // Sortir de la boucle car on ne veut pas continuer à vérifier d'autres ennemis
                break;
            }
        }

        // Si la balle a été supprimée, il faut arrêter l'itération sur les balles
        if (balleSupprimee)
        {
            break;
        }
    }
}

