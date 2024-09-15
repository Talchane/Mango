#include "raylib.h"
#include "raymob.h"
#include <cmath>
#include <vector>
#include <string>
#include <random>

using namespace std;

#include "Clock.hpp"
#include "Bouton.hpp"
#include "Ball.hpp"
#include "Personnage.hpp"
#include "Ennemy.hpp"
#include "Lecteur_niveau.hpp"
#include "Game.hpp"


int main()
{

    srand(time(NULL));

    InitWindow(0, 0, "Mango");
    SetTargetFPS(144);

    Vector2 ScreenDims {(float)GetScreenWidth(), (float)GetScreenHeight() };

    Game game(ScreenDims);

    Clock clock;
    while (!WindowShouldClose())
    {
        double dt { clock.restart() };
        game.actualize(dt);

        BeginDrawing();
        ClearBackground((Color){230, 230, 230});
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
