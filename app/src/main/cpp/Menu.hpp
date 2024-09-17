#ifndef MANGO_MENU_H
#define MANGO_MENU_H

#include <string>
#include "raylib.h"
#include "Bouton.hpp"
#include "Selecteur_niveaux.hpp"
#include "Ingame.hpp"



class Menu {
public:
    Menu(Vector2 const& ScreenDims, std::string * ptst, Ingame *_Ingame_ptr_);

    void actualize(const float dt);	// Actualise tout
    void Draw();    // Affiche tout

    std::string * ptstate;
    Ingame *Ingame_ptr;

private:
    Bouton startInfiniButton;
    Bouton selectNiveauButton;
    SelecteurNiveaux selecteur;
};


#endif //MANGO_MENU_H