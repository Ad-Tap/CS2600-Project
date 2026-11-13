// File for Pencil, eraser, line, and shapes
#include "raylib.h"

void DrawShapes(int screenWidth, int screenHeight){

      DrawText("Some basic shapes available on raylib", 20, 20, 20, BLACK);

      // Establishes circle shapes and lines
      DrawCircle(screenWidth/5, 120, 35, BLACK);
      DrawCircleGradient(screenWidth/5.0f, 220.0f, 60, BLACK, BLACK);
      DrawCircleLines(screenWidth/5, 340, 80, BLACK);
      DrawEllipse(screenWidth/5, 120, 25, 20, BLACK);
      DrawEllipseLines(screenWidth/5, 120, 30, 25, BLACK);

      // Establishes our rectangle shapes and lines
      DrawRectangle(screenWidth/4*2 - 60, 100, 120, 60, BLACK);
      DrawRectangleGradientH(screenWidth/4*2 - 90, 170, 180, 130, BLACK, BLACK);
      DrawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, BLACK);

      //Establishes the triangle shapes and lines
      DrawTriangle((Vector2){ screenWidth/4.0f *3.0f, 80.0f },
                   (Vector2){ screenWidth/4.0f *3.0f - 60.0f, 150.0f },
                   (Vector2){ screenWidth/4.0f *3.0f + 60.0f, 150.0f }, BLACK);

      DrawTriangleLines((Vector2){ screenWidth/4.0f*3.0f, 160.0f },
                        (Vector2){ screenWidth/4.0f*3.0f - 20.0f, 230.0f },
                        (Vector2){ screenWidth/4.0f*3.0f + 2.0f, 230.0f }, BLACK);
      // Make polygon shapes and lines
      DrawPoly((Vector2){ screenWidth/4.0f*3, 330 }, 6, 80, BLACK);
      DrawPolyLines((Vector2){ screenWidth/4.0f*3, 330 }, 6, 90, BLACK);
      DrawPolyLinesEx((Vector2){ screenWidth/4.0f*3, 330 }, 6, 85, 6, BLACK);

      // Renders all lines in a single draw pass
      DrawLine(18,42, screenWidth -18, 42, BLACK);
  }
  

