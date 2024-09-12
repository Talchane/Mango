#include "raylib.h"
#include "raymob.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Initialize the window
    InitWindow(800, 600, "C++ Raylib Example");
    SetTargetFPS(60);

    // Initialize the screen size after InitWindow
    Vector2 Screen = { (float)GetScreenWidth(), (float)GetScreenHeight() };

    // Main game loop
    while (!WindowShouldClose())
    {
        if (GetTouchPointCount() > 0)
            Vibrate(0.1f);

        Vector2 center = { Screen.x / 2, Screen.y / 2 };
        Color customColor = { 120, 120, 120, 255 };
        Vector2 gauche = { center.x - 75, center.y};
        Vector2 droite = { center.x + 75, center.y};

        BeginDrawing();
        ClearBackground(customColor);
        DrawCircleV(gauche, 100, BLUE);
        DrawCircleV(center, 100, WHITE);
        DrawCircleV(droite, 100, RED);
        EndDrawing();
    }

    // Close the window
    CloseWindow();
    return 0;
}
