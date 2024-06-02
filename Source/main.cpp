#include "raylib.h"
#include "Game.hpp"

int main(void)
{   
    const int screenWidth = 320;
    const int screenHeight = 340;

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