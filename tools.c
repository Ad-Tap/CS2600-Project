#include "raylib.h"
#include <math.h>

// Helper function for main function with has the logic to build the shapes dyamically
void DrawShapeOnImage(Image *dst, Vector2 start, Vector2 end, int shapeType, Color color){
  // This first converts the screen coordinates to the raylib coordinates
  int x1 = (int)start.x;
  int y1 = dst->height - (int)start.y;
  int x2 = (int)end.x;
  int y2 = dst->height - (int)end.y);

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
    case0:
      ImageDrawRectangle(dst, x, y, width, height, color);
      break;
    // Circles
    case1:
    {
      int centerX = x + width / 2;
      int centerY = y + height / 2;
      int radius = (width > height ? width: height) / 2;
      ImageDrawCircle(dst, centerX, centerY, radius, color);
    }
    break;
    // Lines
    case2:
      ImageDrawLine(dst, x1, y1, x2, y2, color);
      break;
    default:
      break;
  }
}
