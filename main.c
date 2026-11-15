#include "raylib.h"
#include <stdio.h>
#include <string.h>

char mode[] = "pen";

// returns corresponding int if string is a valid mode. Returns -1 otherwise. 
int modeToInt(char mode[]);
void fill(Image* image, int x, int y, Color fillColor);
void fillHelper(Image* image, int x, int y, Color fillColor, Color originalPixelColor);

int main(void)
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Paint App");
	Image canvas = GenImageColor(SCREEN_WIDTH, SCREEN_HEIGHT, RAYWHITE);

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
					ImageDrawCircle(&canvas, pos.x, SCREEN_HEIGHT - pos.y, penSize, BLUE);
				}
				if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
					fill(&canvas, pos.x, pos.y, BLACK);
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

		UpdateTexture(target.texture, canvas.data);
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

// ISSUE: fill() and fillHelper() need some sort of out of bounds check. currently crashes if filling out of any non enclosed shape
void fill(Image* image, int x, int y, Color fillColor) {
	y = image->height - y; // convert to coordinate system of image

	Color originalPixelColor = GetImageColor(*image, x, y);
	Color *pixel = image->data;
	Color targetPixel = pixel[x + y * (int)image->width];
	
	// changes clicked pixel to the desired color 
	pixel[x + y * (int)image->width] = fillColor;
	
	//tries to change all adjacent pixels
	fillHelper(image, x+1, y, fillColor, originalPixelColor);
	fillHelper(image, x, y+1, fillColor, originalPixelColor);
	fillHelper(image, x-1, y, fillColor, originalPixelColor);
	fillHelper(image, x, y-1, fillColor, originalPixelColor);
}

void fillHelper(Image* image, int x, int y, Color fillColor, Color originalPixelColor) {

	Color *pixel = image->data;
	Color targetPixel = pixel[x + y * (int)image->width];
	
	if (ColorIsEqual(targetPixel, originalPixelColor)) {
		pixel[x + y * (int)image->width] = fillColor;
		
		// checks all adjacent pixels
		if (!ColorIsEqual(pixel[(x+1) + y * (int)image->width], fillColor)) {
			fillHelper(image, x+1, y, fillColor, originalPixelColor);
		}
		if (!ColorIsEqual(pixel[x + (y+1) * (int)image->width], fillColor)) {
			fillHelper(image, x, y+1, fillColor, originalPixelColor);
		}
		if (!ColorIsEqual(pixel[(x-1) + y * (int)image->width], fillColor)) {
			fillHelper(image, x-1, y, fillColor, originalPixelColor);
		}
		if (!ColorIsEqual(pixel[x + (y-1) * (int)image->width], fillColor)) {
			fillHelper(image, x, y-1, fillColor, originalPixelColor);
		}
	
	}
}
