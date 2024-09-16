#include "Game.hpp"

Game::Game(Vector2 const& ScreenDims) : startButton(ScreenDims.x / 2, ScreenDims.y / 2, 150, 150, BLUE, "Start"),
                                        ingame(ScreenDims, &textures, &state),
                                        menu(ScreenDims, &state)
{
    textures.loadAll();
}

void Game::actualize(const float dt)
{
    if (state == "Ingame") // Si on est en partie
    {
        ingame.actualize(dt);
    }
    if( state == "Menu" )    // On est sur le menu
    {
        menu.actualize(dt);
    }
}

void Game::Draw()
{
    if ( state == "Ingame" )
    {
        ingame.Draw();
    }
    if( state == "Menu" )
    {
        menu.Draw();
    }
}


