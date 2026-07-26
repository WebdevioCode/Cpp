#include <iostream>
#include "raylib.h"

int main() {
  const int screenWidth = 800;
  const int screenHight = 450;

  InitWindow(screenWidth, screenHight, "First mini game kinda");

  SetTargetFPS(60);

  Rectangle box = {300,150,200,100};
  Rectangle player = {0,0,50,50};

  while (!WindowShouldClose()) {
    Vector2 mousePos = GetMousePosition();
    player.x = mousePos.x - player.width / 2.0f;
    player.y = mousePos.y - player.height / 2.0f;

    bool isColliding = CheckCollisionRecs(player,box);

    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawRectangleRec(box, isColliding ? RED : BLUE);
      DrawRectangleLinesEx(box, 3, DARKBLUE);
      DrawRectangleRec(player, GREEN);

      DrawText("Move the green one to the blue one", 10,10,20,DARKGRAY);
    EndDrawing();

  }

  return 0;
}
