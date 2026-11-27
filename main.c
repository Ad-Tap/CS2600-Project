# include "raylib.h"
#include <stdio.h>
#include <string.h>
#include "tools.c"

// sized to fit the longest mode name ("eraser" / "shapes") so strcpy can switch modes safely
char mode[16] = "pen";

// returns corresponding int if string is a valid mode. Returns -1 otherwise. 
int modeToInt(char mode[]);

int main(void)
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Paint App");

	HideCursor();

	RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

	//drawing pencil/pen vars + save old pencil position to fill in gaps.
	int penSize = 2;
	Vector2 lastPos = GetMousePosition();

	// straight line tool vars
	Vector2 lineStart = { 0, 0 };	// where the user first clicked
	bool isDrawingLine = false;		// true while the mouse is held down in line mode

    while (!WindowShouldClose())
    {
		Vector2 pos = GetMousePosition();

		// keyboard shortcuts for switching tools
		if (IsKeyPressed(KEY_L)) {
			strcpy(mode, "line");
		}
		if (IsKeyPressed(KEY_P)) {
			strcpy(mode, "pen");
			isDrawingLine = false;	// cancel any line that was in progress
		}

		// doesn't work yet. not too sure how texture mode works yet. This might be what allows us to keep what we draw 
		// on the screen. looked at pendulem example in raylib website.
		BeginTextureMode(target);
		
		switch (modeToInt(mode)) {
			case 0: 
				// pen mode
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){ //true for 1 frame
					lastPos = pos;
				}
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) { //continuously true
					DrawLineEx(lastPos, pos, penSize * 2, BLUE); 
					//DrawCircle(pos.x, pos.y, penSize, BLUE);
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
				break;
			case 3:
				// line mode: click to set the start point, hold to drag, release to draw
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					lineStart = pos;
					isDrawingLine = true;
				}

				if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isDrawingLine) {
					// only now is the line drawn onto the canvas permanently
					DrawLineEx(lineStart, pos, penSize * 2, BLUE);
					isDrawingLine = false;
				}
				break;
			case 4:
				// fill mode
				break;
			default: 
				printf("Invalid Mode\n");
				break;
		}
		
		
		
		EndTextureMode();
		
		lastPos = pos;	//remember this frame mouse pos for next frame

		// makes the background and displays blue circle where mouse should be
		BeginDrawing();

		// clear first, otherwise it wipes out the canvas we draw on the next line
		ClearBackground(RAYWHITE);

		// this is used to actually draw the thing drawn in what I believe to be some kind of texture buffer
        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);

		// line preview: drawn to the screen only (not the canvas) so it follows the mouse while dragging
		if (isDrawingLine) {
			DrawLineEx(lineStart, pos, penSize * 2, BLUE);
		}

		DrawCircle(pos.x, pos.y, penSize, BLUE);
		PollInputEvents();
		
		EndDrawing();
    }
	
    CloseWindow();

    return 0;
}


int modeToInt(char mode[]) {
	char *modesArr[] = {"pen", "eraser", "shapes", "line", "fill"}; // referenced https://www.geeksforgeeks.org/c/array-of-strings-in-c/
	int modeIndex = -1;

	for (int i = 0; i < 4; i++) {
		if (strcmp(modesArr[i], mode) == 0) {
			modeIndex = i;
		}
	}
	return modeIndex;
}

