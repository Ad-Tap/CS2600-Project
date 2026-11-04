#include "raylib.h"
#include <stdio.h>

int main(void)
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib example - basic window");

	HideCursor();

	RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!WindowShouldClose())
    {
		Vector2 pos = GetMousePosition();
		//printf("x:%f, y:%f", pos.x, pos.y);
		
		// doesn't work yet. not too sure how texture mode works yet. This might be what allows us to keep what we draw 
		// on the screen. looked at pendulem example in ra ylib website.
		BeginTextureMode(target);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			DrawCircle(pos.x, pos.y, 10, BLUE);
		}
		EndTextureMode();

		// makes the background and displays blue circle where mouse should be
		BeginDrawing();

		// this is used to actually draw the thing drawn in what I believ to be some kind of texture buffer
        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);

		ClearBackground(RAYWHITE);
		DrawCircle(pos.x, pos.y, 10, BLUE);
		PollInputEvents();
		
		EndDrawing();

//		// checks if a is pressed then prints to terminal
//		// can't handle ctrl,alt,super so not yet useful for shortcuts
//		int key = GetKeyPressed();
//		if (key != 0) {
//			printf("%s\n", GetKeyName(key));
//		}


    }

    CloseWindow();

    return 0;
}
