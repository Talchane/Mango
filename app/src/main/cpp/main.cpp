#include "raylib.h"
#include "raymob.h"
#include <cmath>
#include <vector>

using namespace std;

#include "Bouton.hpp"
#include "Ball.hpp"
#include "Personnage.hpp"
#include "Ennemy.hpp"
#include "Game.hpp"


int main()
{
    Game game;

    InitWindow(0, 0, "Mango");
    SetTargetFPS(144);

    Bouton myButton(350, 250, 100, 50, "Tap Me");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        game.Draw();
        myButton.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
