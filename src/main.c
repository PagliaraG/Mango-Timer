#include <stdio.h>
#include "raylib.h"

int main(void) {
    InitWindow(1280,720,"Mango Timer");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("Welcome to Mango Timer!",640,360,24,BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
