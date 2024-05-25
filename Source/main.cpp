#include "raylib.h"
#include "Game.hpp"

int main(void)
{   
    const int screenWidth = 500;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Game Game;

    SetTargetFPS(60);               

    InitAudioDevice();

    while (!WindowShouldClose())
    {
        Game.ProcessInput();
        Game.Update();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        Game.Draw();
        EndDrawing();
    }

    CloseAudioDevice();
    
    CloseWindow();

    return 0;
}