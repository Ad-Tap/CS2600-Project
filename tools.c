#include "raylib.h"
#include <math.h>

// Helper function for main function
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
    // Circles
    case1:
    // Lines
    case2:
    default:
  }
}
