#ifndef MANGO_MENU_H
#define MANGO_MENU_H

#include <string>
#include "raylib.h"
#include "Bouton.hpp"



class Menu {
public:
    Menu(Vector2 const& ScreenDims, std::string * ptst);

    void actualize(const float dt);	// Actualise tout
    void Draw();    // Affiche tout

    std::string * ptstate;

private:
    Bouton startButton;
};


#endif //MANGO_MENU_H