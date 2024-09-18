//
// Created by benfe on 18/09/2024.
//

#ifndef MANGO_PAUSE_MENU_HPP
#define MANGO_PAUSE_MENU_HPP

#include "raylib.h"
#include "Bouton.hpp"
#include "Clock.hpp"
#include "Fonctions.hpp"

class PauseMenu
{
public:
    PauseMenu(string *_state_ptr_, const Vector2& screenDims, const initializer_list<Clock *> &_clocks_);
    void actualize();
    void Draw() const;
    void show();


private:
    Vector2 position;
    Rectangle fondRect;
    Bouton playButton;
    Bouton exitButton;

    vector<Clock*> clocks;
    string *state_ptr;
};


#endif //MANGO_PAUSE_MENU_HPP
