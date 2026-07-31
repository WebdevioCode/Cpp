#include <iostream>
#include "raylib.h"

struct Player {
    Vector2 position;
    Vector2 velocity;
};

void resetGame(Player& player, float WIDTH, float HEIGHT, bool& gameOver, int& score ); 

int main() {
    const float WIDTH{450.0f};
    const float HEIGHT{800.0f};
    int score{};

    InitWindow(WIDTH,HEIGHT, "Flappy bird");
    SetTargetFPS(144);

     Texture2D background{LoadTexture("imgs/flappyBirdBackground.png")};

    if (background.id == 0) {
        std::cout << "FAILED TO LOAD TEXTURE\n";
    } else {
        std::cout << "Texture loaded!\n";
    }
    
    Player player {
        {WIDTH / 2 - 25.0f , HEIGHT / 2},
        {0.0f,0.0f }
    };

   const float gravity{1200.0f};
   const float jumpForce{-350.0f};
   bool gameOver{false};


    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (!gameOver) {
            if (IsKeyPressed(KEY_SPACE)) player.velocity.y = jumpForce;

            player.velocity.y += gravity * dt;
            player.position.y += player.velocity.y * dt;

            if (player.position.y <= 0 || player.position.y >= HEIGHT - 50.0f) {
                gameOver = true;
            }
        } else {
            if (IsKeyPressed(KEY_R)) resetGame(player, WIDTH, HEIGHT, gameOver, score);
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(background, 0, 0, WHITE);
            if (!gameOver) { 
                DrawRectangle(player.position.x, player.position.y, 50, 50, BLACK);
            } else {
                DrawText("Game Over", 110 , 350, 40, RED);
                DrawText("Press R to restart", 125 , 410, 20, LIGHTGRAY);
            }
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
    return 0;
}

void resetGame(Player& player, float WIDTH, float HEIGHT, bool& gameOver, int& score ) {
    player.position = {WIDTH / 2 - 25.0f, HEIGHT / 2};
    player.velocity = {0.0f, 0.0f};
    gameOver = false;
    score = 0;
}
