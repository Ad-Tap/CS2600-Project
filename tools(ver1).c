// Old file
// File for Pencil, eraser, line, and shapes
#include "raylib.h"

void DrawShapes(int screenWidth, int screenHeight){

      DrawText("Some basic shapes available on raylib", 20, 20, 20, BLACK);

      float col1X = screenWidth * 0.20f;
      // Establishes circle shapes and lines
      DrawCircle(col1X, screenHeight * 0.26f, 35, BLACK);
      DrawCircleGradient(col1X, screenHeight * 0.48f, 60, BLACK, GRAY);
      DrawCircleLines(col1X, screenHeight * 0.75f, 80, BLACK);
      DrawEllipse(col1X, screenHeight * 0.26f, 25, 20, BLACK);
      DrawEllipseLines(col1X, screenHeight * 0.26f, 30, 25, BLACK);

      float col2X = screenWidth * 0.50f;

      // Establishes our rectangle shapes and lines
      DrawRectangle(col2X - 60, screenHeight * 0.22f, 120, 60, BLACK);
      DrawRectangleGradientH(col2X - 90, screenHeight * 0.37f, 180, 130, BLACK, GRAY);
      DrawRectangleLines(col2X - 40, screenHeight * 0.71f, 80, 60, BLACK);

      float col3X = screenWidth * 0.75f;
      //Establishes the triangle shapes and lines
      DrawTriangle((Vector2){ col3X, screenHeight * 0.17f }, 
                 (Vector2){ col3X - 60.0f, screenHeight * 0.33f }, 
                 (Vector2){ col3X + 60.0f, screenHeight * 0.33f }, BLACK);

      DrawTriangleLines((Vector2){ col3X, screenHeight * 0.35f }, 
                      (Vector2){ col3X - 20.0f, screenHeight * 0.51f }, 
                      (Vector2){ col3X + 20.0f, screenHeight * 0.51f }, BLACK);
      // Make polygon shapes and lines
      DrawPoly((Vector2){ col3X, screenHeight * 0.73f }, 6, 80, 0.0f, BLACK);
      DrawPolyLines((Vector2){ col3X, screenHeight * 0.73f }, 6, 90, 0.0f, BLACK);
      DrawPolyLinesEx((Vector2){ col3X, screenHeight * 0.73f }, 6, 85, 0.0f, 6, BLACK);

      // Renders all lines in a single draw pass
      DrawLine(18, 42, screenWidth - 18, 42, BLACK);
  }
  

