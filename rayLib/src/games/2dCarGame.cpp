    #include <iostream>
    #include "raylib.h"
    #include <random>

    //2d car game


    struct Player {
        Vector2 position;
        Vector2 velocity;
    };

    struct Enemy {
        Vector2 position;
        Vector2 velocity;
    };

    int randomNumberGen(int WIDTH);
    void resetGame(Player& player,  Enemy& enemy1, int WIDTH, int HEIGHT, bool& gameOver, int& score ); 

    int main() {

        const int WIDTH{450};
        const int HEIGHT{800};

        SetTargetFPS(180);

        InitWindow(WIDTH, HEIGHT, "2d car game");

        Player player {
            {WIDTH / 2 -35, HEIGHT / 2},
            {350.0f, 350.0f},
        };

        Enemy enemy1 {
            {randomNumberGen(WIDTH), -100},
            {350.0f, 350.0f},
        };

        int score{};
        bool gameOver{false};

        while (!WindowShouldClose()) {
            float dt = GetFrameTime();

            if (!gameOver) {

                if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.position.y -= player.velocity.y * dt;
                if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) player.position.x -= player.velocity.x * dt;  
                if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) player.position.x += player.velocity.x * dt; 
                if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.position.y += player.velocity.y * dt;
                
                if (player.position.y > HEIGHT - 100) player.position.y = HEIGHT - 100;
                if (player.position.y < 0) player.position.y = 0;
                if (player.position.x > WIDTH - 50) player.position.x = WIDTH - 50;
                if (player.position.x < 0) player.position.x = 0;


                enemy1.position.y += enemy1.velocity.y * dt;

                if (enemy1.position.y > HEIGHT) {
                    enemy1.position.y = -100;
                    enemy1.position.x = randomNumberGen(WIDTH);
                    score++;

                }

                Rectangle playerRect {
                    player.position.x,
                    player.position.y,
                    50, 
                    100 
                };

                Rectangle enemy1Rect {
                    enemy1.position.x,
                    enemy1.position.y,
                    50,
                    100
                };

                if (CheckCollisionRecs(playerRect, enemy1Rect)) gameOver = true;
            } else {
                if (IsKeyPressed(KEY_R)) resetGame(player, enemy1, WIDTH, HEIGHT, gameOver, score);
            }
            
            

            BeginDrawing();
                    ClearBackground(LIGHTGRAY);

                    if (!gameOver) {
                        DrawRectangle(player.position.x, player.position.y, 50, 100, BLUE);
                        DrawRectangle(enemy1.position.x, enemy1.position.y, 50, 100, RED);
                        DrawText(TextFormat("%i", score),20, 20, 60, BLACK);
                    } else {
                        DrawText("Game Over", 110 , 350, 40, RED);
                        DrawText("Press R to restart", 125 , 410, 20, BLACK);
                    }
            EndDrawing();
        }
        CloseWindow();
        return 0;
    }

    int randomNumberGen(int WIDTH) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> random(0, static_cast<int>(WIDTH) - 50);
    
    return random(gen);
    }

    void resetGame(Player& player,  Enemy& enemy1, int WIDTH, int HEIGHT, bool& gameOver, int& score ) {
        player.position.x = WIDTH / 2 -35;
        player.position.y = HEIGHT / 2;
        player.velocity.x = 350.0f;
        player.velocity.y = 350.0f;

        enemy1.position.x = randomNumberGen(WIDTH);
        enemy1.position.y = -100;
        enemy1.velocity.x = 350.0f;
        enemy1.velocity.y = 350.0f;

        gameOver = false;
        score = 0;
    }
