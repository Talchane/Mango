#include "Game.hpp"

Game::Game(Vector2 const& ScreenDims) : ingame(ScreenDims, &textures, &state),
                                        menu(ScreenDims, &state, &ingame)
{
    textures.loadAll();
}

void Game::actualize(const float dt)
{
    if (state == "Ingame") // Si on est en partie
    {
        ingame.actualize(dt);
    }
    if( state == "Menu" || state == "choixLevel" )    // On est sur le menu
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
    if( state == "Menu" || state == "choixLevel" )
    {
        menu.Draw();
    }
}


