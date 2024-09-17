//
// Created by benfe on 17/09/2024.
//

#ifndef MANGO_SELECTEUR_NIVEAUX_HPP
#define MANGO_SELECTEUR_NIVEAUX_HPP

#include "raylib.h"
#include "Bouton.hpp"
#include "vector"
#include "Fonctions.hpp"
#include "Ingame.hpp"

using namespace std;

class SelecteurNiveaux
{
public:
    SelecteurNiveaux(string * ptst, Ingame *_Ingame_ptr_);
    void actualize();
    void Draw();

    Rectangle fondRect;
    vector<Bouton> boutons;
    unsigned int niveauActuel;

    string *state_ptr;
    Ingame *Ingame_ptr;

private:
    unsigned int InitButtons();
};


#endif //MANGO_SELECTEUR_NIVEAUX_HPP
