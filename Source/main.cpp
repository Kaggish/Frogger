#include "raylib.h"
#include "Game.hpp"

int main(void)
{   
    const int screenWidth = 800;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "Frogger");
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