//
// Created by benfe on 17/09/2024.
//

#include "Selecteur_niveaux.hpp"

SelecteurNiveaux::SelecteurNiveaux(string * ptst, Ingame *_Ingame_ptr_) :   niveauActuel(0),
                                                                            state_ptr(ptst),
                                                                            Ingame_ptr(_Ingame_ptr_)

{
    fondRect.x = 100;
    fondRect.y = 100;
    fondRect.width = GetScreenWidth() - 200;
    fondRect.height = 1500;

    niveauActuel = InitButtons();
    LOGE("Nombre de niveaux : %d", niveauActuel);
}

void SelecteurNiveaux::actualize()
{
    for (int i = 0; i < size(boutons); ++i)
    {
        if (boutons[i].isPressed())
        {
            (*Ingame_ptr).numLevel = i+1;
            *state_ptr = "Ingame";
            (*Ingame_ptr).Start();
        }
    }
}

void SelecteurNiveaux::Draw()
{
    DrawRectangleRounded(fondRect, 0.3, 8, (Color){80, 35, 35, 255});

    for (int i = 0; i < size(boutons); ++i)
        boutons[i].Draw(false);
}

// Crée le bon nombre de boutons de niveau et renvoie le nombre de niveaux accessibles
unsigned int SelecteurNiveaux::InitButtons()
{
    string root { "Levels/" };
    string filename = "lvl_1.txt";

    int numLvl = 0; // L'index a 1 de décalage avec le numéro du niveau
    int sizeBoutons = 170;

    while (LoadFileText((root + filename).c_str()))
    {
        float interButton = fondRect.width / 3 - 100;
        float x = fondRect.x + 50 + interButton * (1 + numLvl % 3);
        float y = fondRect.y + 50 + interButton * int(1 + numLvl / 3);

        Color colorButtons = (Color){0, 0, 255, 255};
        string texte = to_string(++numLvl);
        boutons.emplace_back(x, y, sizeBoutons, sizeBoutons, colorButtons, texte.c_str());
        boutons.back().buttonTextColor = (Color){0, 255, 0, 255};
        boutons.back().fontSize = 60;

        filename = "lvl_" + to_string(numLvl + 1) + ".txt";
    }

    return numLvl - 1;
}