#include "raylib.h"
#include <stdio.h>

int main(void)
{
    InitWindow(800, 450, "raylib example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();

		// checks if A is pressed then prints to terminal
		if (IsKeyPressed(KEY_A)) {
			printf("%s\n", GetKeyName(GetKeyPressed()));
		}

    }

    CloseWindow();

    return 0;
}
