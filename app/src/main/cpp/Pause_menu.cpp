//
// Created by benfe on 18/09/2024.
//

#include "Pause_menu.hpp"

// Attention, cette classe doit prendre en paramètre absolument toutes les Clock du code. Le paramètre est variadic

PauseMenu::PauseMenu(string *_state_ptr_, const Vector2& screenDims, const initializer_list<Clock *> &_clocks_) :
            state_ptr(_state_ptr_),
            position({(float)screenDims.x / 2.f, (float)screenDims.y / 2.f}),
            fondRect({position.x - 300, position.y - 300, 600, 600}),
            playButton(fondRect.x + fondRect.width / 2, fondRect.y + 150, 500, 100, {127, 127, 127, 255}, "Resume"),
            exitButton(fondRect.x + fondRect.width / 2, fondRect.y + 300, 500, 100, {127, 127, 127, 255}, "Exit")
{
    for (auto cl : _clocks_)
        clocks.push_back(cl);

    playButton.fontSize = 45;
    exitButton.fontSize = 45;
}

void PauseMenu::actualize()
{
    if (playButton.isPressed())
    {
        for (int i = 0; i < size(clocks); ++i)
            clocks[i] -> play();

        (*state_ptr) = "Ingame";
    }
    if (exitButton.isPressed())
    {
        (*state_ptr) = "Menu";

        for (int i = 0; i < size(clocks); ++i)
            clocks[i] -> restart();
    }
}

void PauseMenu::Draw() const
{
    // Filtre transparent
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), {200, 200, 255, 127});

    // Fond du menu
    DrawRectangleRounded(fondRect, 0.3f, 8, {80, 40, 40, 255});


    // Boutons
    playButton.Draw(true);
    exitButton.Draw(true);
}

void PauseMenu::show()
{
    for (int i = 0; i < size(clocks); ++i)
        clocks[i] -> pause();
}
