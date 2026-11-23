#include "raylib.h"
#include <stdio.h>
#include "tools.c"

char mode[] = "pen";

int main(void)
{
	const int SCREEN_WIDTH = 900;
	const int SCREEN_HEIGHT = 600;
	const int TOOLBAR_HEIGHT = 30;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT+TOOLBAR_HEIGHT, "Paint App");

	HideCursor();

	RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

	//drawing pencil/pen vars
	int penSize = 2;

    while (!WindowShouldClose())
    {
		Vector2 pos = GetMousePosition();
		
		// doesn't work yet. not too sure how texture mode works yet. This might be what allows us to keep what we draw 
		// on the screen. looked at pendulem example in ra ylib website.
		BeginTextureMode(target);
		
		switch (modeToInt(mode)) {
			case 0: 
				// pen mode
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
					DrawCircle(pos.x, pos.y, penSize, BLUE);
				}
				if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
					fill(target.texture, pos.x, pos.y, BLACK);
				}
				break;
			case 1:
				// simplified eraser. Doest't actually look great yet
				if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
					DrawCircle(pos.x, pos.y, penSize, RAYWHITE);
				}
			case 4:
				// fill mode
				break;
			default: 
				printf("Invalid Mode\n");
				break;
		}	
		EndTextureMode();


		// makes the background and displays blue circle where mouse should be
		BeginDrawing();
		//background for tool section
		DrawRectangle(0, SCREEN_HEIGHT, SCREEN_WIDTH, TOOLBAR_HEIGHT, GRAY); 

		// this is used to actually draw the thing drawn in what I believe to be some kind of texture buffer
        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
		

		ClearBackground(RAYWHITE);
		DrawCircle(pos.x, pos.y, penSize, BLUE);
		PollInputEvents();

		
		EndDrawing();
    }
	
    CloseWindow();

    return 0;
}


