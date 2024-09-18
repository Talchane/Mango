#include "Game.hpp"

Game::Game(Vector2 const& ScreenDims) : textures(),
                                        ingame(ScreenDims, &textures, &state),
                                        menu(ScreenDims, &state, &ingame)
{
    LOGE("Game ScreenDims : %f, %f", ScreenDims.x, ScreenDims.y);
}

void Game::actualize(const float dt)
{
    if (state == "Ingame" || state == "PauseMenu") // Si on est en partie
    {
        ingame.actualize(dt);
    }
    if (state == "Menu" || state == "choixLevel")    // On est sur le menu
    {
        menu.actualize(dt);
    }
}

void Game::Draw()
{
    if (state == "Ingame" || state == "PauseMenu")
    {
        ingame.Draw();
    }
    if (state == "Menu" || state == "choixLevel")
    {
        menu.Draw();
    }
}


