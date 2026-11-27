#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include "colors.c"
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

	int penSize = 2;
	int colorIndex = 0;
	setSelectedColor(colorIndex);
	Vector2 lastPos = GetMousePosition();

    while (!WindowShouldClose())
    {
		Vector2 pos = GetMousePosition();

		// cycle palette colors with left/right arrows
		if (IsKeyPressed(KEY_RIGHT)) {
			colorIndex = (colorIndex + 1) % getColorCount();
			setSelectedColor(colorIndex);
		}
		if (IsKeyPressed(KEY_LEFT)) {
			colorIndex = (colorIndex - 1 + getColorCount()) % getColorCount();
			setSelectedColor(colorIndex);
		}

		Color activeColor = getSelectedColor();

		BeginTextureMode(target);

		switch (modeToInt(mode)) {
			case 0: 
				// pen mode
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					lastPos = pos;
				}
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
					// connect lastPos to pos to avoid gaps
					DrawLineEx(lastPos, pos, penSize * 2.0f, activeColor);
					lastPos = pos;
				}
				if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
					fill(target.texture, (int)pos.x, (int)pos.y, activeColor);
				}
				break;
			case 1:
				// simplified eraser. Doest't actually look great yet
				if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
					DrawCircle(pos.x, pos.y, penSize, RAYWHITE);
				}
				break;
			case 2:
				// shape mode
				updateShapeTool(&target, pos, 0, activeColor);
				break;
			case 4:
				// fill mode
				break;
			default: 
				printf("Invalid Mode\n");
				break;
		}

		EndTextureMode();

		BeginDrawing();

		ClearBackground(RAYWHITE);

        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);

		DrawCircle(pos.x, pos.y, penSize, activeColor);
		PollInputEvents();

		EndDrawing();
    }

    CloseWindow();

    return 0;
}


int modeToInt(char mode[]) {
	char *modesArr[] = {"pen", "eraser", "shapes", "line", "fill"}; // referenced https://www.geeksforgeeks.org/c/array-of-strings-in-c/
	int modeIndex = -1;

	for (int i = 0; i < 5; i++) {
		if (strcmp(modesArr[i], mode) == 0) {
			modeIndex = i;
		}
	}
	return modeIndex;
}
