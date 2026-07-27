#include <iostream>
#include "raylib.h"

int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Keyboard Movements");

  SetTargetFPS(60);

  Rectangle player = {400 - 25 , 255 - 25, 50, 50};
  float speed = 300.0f;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.x += speed * dt;
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) player.x -= speed * dt;
    if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) player.y += speed * dt;
    if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) player.y -= speed * dt;
    
    if(player.x < 0) player.x = 0;
    if(player.x > screenWidth - 50) player.x = screenWidth - 50;
    if(player.y < 0) player.y = 0;
    if(player.y > screenHeight - 50) player.y = screenHeight - 50;

    BeginDrawing();
      ClearBackground(RAYWHITE);

      DrawRectangleRec(player, MAROON);

      DrawText("Use WASD or ARROW KEYS to move", 10,10,20, DARKBLUE);
    EndDrawing();
  }
  return 0;
}
