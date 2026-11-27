#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include "tools.c"
#include "colors.c"


int getColorCount(void);
Color getSelectedColor(void);
void setSelectedColor(int index);
Color getColorPalette(int index);
char mode[] = "pen"; // default mode is shapes. This is a global variable that can be changed by the user to change the mode of the program.

// returns corresponding int if string is a valid mode. Returns -1 otherwise. 
int modeToInt(char mode[]);

int main(void)
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Paint App");

	HideCursor();

	RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

	BeginTextureMode(target);
	ClearBackground(RAYWHITE);
	EndTextureMode();

	//drawing pencil/pen vars
	int penSize = 2;
	int colorIndex = 0;

    while (!WindowShouldClose())
    {

		Vector2 pos = GetMousePosition();
		if (IsKeyPressed(KEY_RIGHT)){
			colorIndex = (colorIndex + 1) % getColorCount();
			setSelectedColor(colorIndex);
			printf("Color index: %d\n", colorIndex);
		} 
		if (IsKeyPressed(KEY_LEFT)){
			colorIndex = (colorIndex - 1 + getColorCount()) % getColorCount();
			setSelectedColor(colorIndex);
			printf("Color index: %d\n", colorIndex);
		}
		Color activeColor = getSelectedColor();
		
		// doesn't work yet. not too sure how texture mode works yet. This might be what allows us to keep what we draw 
		// on the screen. looked at pendulem example in ra ylib website.
		BeginTextureMode(target);
		
		switch (modeToInt(mode)) {
			case 0: 
				// pen mode
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
					DrawCircle(pos.x, pos.y, penSize, activeColor);
				}
				if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
					fill(target.texture, pos.x, pos.y, activeColor);
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


		// makes the background and displays blue circle where mouse should be
		BeginDrawing();

		ClearBackground(RAYWHITE);

		// this is used to actually draw the thing drawn in what I believe to be some kind of texture buffer
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
