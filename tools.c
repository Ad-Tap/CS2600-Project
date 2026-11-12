// File for Pencil, eraser, line, and shapes
#include "raylib.h"

int main(void){

  //Initializes our variables
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, raylib [shapes] example - basic shapes");

  float rotation = 0.0f;
  SteTargetFPS(60);

  // Sets up our shapes window to update and draw
  while (!WindowShouldClocese()){
    rotate += 0.2f;
    BeginDrawing();
      ClearBackground(RAYWHITE);

      DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY);

      // Establishes circle shapes and lines
      DrawCircle(screenWdith/5, 120, 35, DARKBLUE);
      DrawCircleGradient((Vector 2){ screenWidth/5.0f, 220.0f }, 60, GREEN, SKYBLUE);
      DrawCircleLines(screenWidth/5, 340, 80, DARKBLUE);
      DrawEllipse(screenWidth/5, 120, 25, 20, YELLOW);
      DrawEllipseLines(screenWidth/5, 120, 30, 25, YELLOW);
      {
}

