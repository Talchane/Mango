#include "Ingame.hpp"

Ingame::Ingame(Vector2 const& ScreenDims, TextureLoader *_textures_ptr_, string * _state_ptr_) :
        player(ScreenDims, _textures_ptr_, &correspondances),
        textures_ptr(_textures_ptr_),
        state_ptr(_state_ptr_)
{
    for (int i = 0; i < size(colorButtons); ++i) {
        colorButtons[i] = Bouton(ScreenDims.x / 2 - 200 + i * 200, ScreenDims.y - 200, 150, 150, RED, "");
    }

    colorButtons[0].buttonColor = {255, 0, 0, 255};
    colorButtons[1].buttonColor = {0, 255, 0, 255};
    colorButtons[2].buttonColor = {0, 0, 255, 255};

    correspondances["Red"] = (Color){255, 0, 0, 255};
    correspondances["Green"] = (Color){0, 255, 0, 255};
    correspondances["Blue"] = (Color){0, 0, 255, 255};
}

void Ingame::actualize(const float dt)
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
        if (colorButtons[i].isPressed(10))
            player.setColor(colorButtons[i].buttonColor);
    }
}

void Ingame::Draw()
{
    player.Draw(true);

    for (int i = 0; i < ennemies.size(); ++i)
        ennemies[i].Draw();
    for (int i = 0; i < size(colorButtons); ++i)
        colorButtons[i].Draw(colorButtons[i].buttonColor == player.shootColor);
}

// Si numLevel == 0 alors on est en mode infini
void Ingame::Start()
{
    // Mode infini
    if (numLevel == 0)
    {

    }
        // On charge un niveau
    else
    {
        level.loadLvl(numLevel);
    }

    clockLevel.restart();
    clockInfini.restart();
}


void Ingame::checkSpawn()
{
    if (numLevel == 0)  // Mode infini
    {
        if (clockInfini.getElapsedTime() > 2.f)
        {
            clockInfini.restart();

            // Générer un nombre aléatoire d'ennemis
            for (int i = 0; i < rand() % 3 + 1; ++i)
            {
                // Générer une couleur léatoire pour chaque ennemi
                int index = rand() % size(correspondances);
                auto it(correspondances.begin());
                advance(it, index);

                ennemies.emplace_back(correspondances[it -> first], textures_ptr->texAnneau80);
            }
        }
    }

    // ------------ Dans un niveau ------------
    else
    {
        if (level.ended())
            return;

        if (clockLevel.getElapsedTime() > level.getNextTimeCode())
        {
            for (int i = 0; i < level.getNextQuantity(); ++i)
            {
                string newType(level.getNextType());

                ennemies.emplace_back(correspondances[newType], textures_ptr->texAnneau80);
            }
            level.nextStep();

            // ----- Check fin niveau ---------
            if (level.ended())
            {
                //  --------- Niveau vient de se terminer ----------
            }
        }
    }
}

void Ingame::checkCollisionsTirs()
{
    // -------------- Check collision ennemi --------------
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

    // ----------- Check sortie d'écran ----------
    for (int i = 0; i < player.balles.size(); ++i)  // Utiliser .size() pour la lisibilité
    {
        if (!CheckCollisionPointRec(player.balles[i].position, (Rectangle){0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}))
            removeElement(player.balles, i);
    }
}