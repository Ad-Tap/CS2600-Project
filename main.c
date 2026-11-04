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

		// checks if a is pressed then prints to terminal
		// can't handle ctrl,alt,super so not yet useful for shortcuts
		int key = GetKeyPressed();
		if (key != 0) {
			printf("%s\n", GetKeyName(key));
		}

    }

    CloseWindow();

    return 0;
}
