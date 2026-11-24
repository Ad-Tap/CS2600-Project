#include "raylib.h"
#include <math.h>

void fill(Texture texture, int x, int y, Color fillColor);
void fillHelper(Image* image, int x, int y, Color fillColor, Color originalPixelColor);

// Helper function for main function with the logic to build the shapes dynamically
void DrawShapeOnImage(Image *dst, Vector2 start, Vector2 end, int shapeType, Color color){
  // This first converts the screen coordinates to the raylib coordinates
  int x1 = (int)start.x;
  int y1 = (int)start.y;
  int x2 = (int)end.x;
  int y2 = (int)end.y;

  int x = x1;
  int y = y1;
  int width = x2 - x1;
  int height = y2 - y1;
  // This handles the dragging backwards with negative width or height
  if (width < 0){
    x = x2;
    width = -width;
  }
  if (height <0){
    y = y2;
    height = -height;
  }
  switch (shapeType){
    // Rectangles
    case 0:
      ImageDrawRectangle(dst, x, y, width, height, color);
      break;
    // Circles
    case 1:
    {
      int centerX = x + width / 2;
      int centerY = y + height / 2;
      int radius = (width > height ? width: height) / 2;
      ImageDrawCircle(dst, centerX, centerY, radius, color);
    }
    break;
    // Lines
    case 2:
      ImageDrawLine(dst, x1, y1, x2, y2, color);
      break;
    default:
      break;
  }
}

// This function lets us update the shape tool and handles the actual mouse output
void updateShapeTool(RenderTexture2D *target, Vector2 pos, int shapeType, Color color) {
    static Vector2 shapeStart = {0};
    static bool draggingShape = false;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        shapeStart = pos;
        draggingShape = true;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && draggingShape) {
        Image canvasImg = LoadImageFromTexture(target->texture);
        DrawShapeOnImage(&canvasImg, shapeStart, pos, shapeType, color);
        UpdateTexture(target->texture, canvasImg.data);
        UnloadImage(canvasImg);
        draggingShape = false;
    }
}

// ISSUE: fill() and fillHelper() need some sort of out of bounds check. currently crashes if filling out of any non enclosed shape
void fill(Texture texture, int x, int y, Color fillColor) {
	Image image = LoadImageFromTexture(texture);
	y = image.height - y; // convert to coordinate system of image

	Color originalPixelColor = GetImageColor(image, x, y);
	Color *pixel = image.data;
	Color targetPixel = pixel[x + y * (int)image.width];
	
	// changes clicked pixel to the desired color 
	pixel[x + y * (int)image.width] = fillColor;
	
	//tries to change all adjacent pixels
	fillHelper(&image, x+1, y, fillColor, originalPixelColor);
	fillHelper(&image, x, y+1, fillColor, originalPixelColor);
	fillHelper(&image, x-1, y, fillColor, originalPixelColor);
	fillHelper(&image, x, y-1, fillColor, originalPixelColor);

	UpdateTexture(texture, image.data);
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
